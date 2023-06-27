#include <iostream>
#include <string>
#include <thread>                      // �߳���ͷ�ļ���
#include <mutex>                      // ���������ͷ�ļ���
#include <deque>                      // deque������ͷ�ļ���
#include <queue>                      // queue������ͷ�ļ���
#include <condition_variable>  // ����������ͷ�ļ���
using namespace std;
//class AA
//{
//	mutex m_mutex;                                    // ��������
//	condition_variable m_cond;                  // ����������
//	queue<string, deque<string>> m_q;   // ������У��ײ�������deque��
//public:
//	void incache(int num)     // �������ݣ�numָ�����ݵĸ�����
//	{
//		lock_guard<mutex> lock(m_mutex);   // ���������
//		for (int ii = 0; ii < num; ii++)
//		{
//			static int bh = 1;           // ��Ů��š�
//			string message = to_string(bh++) + "�ų�Ů";    // ƴ�ӳ�һ�����ݡ�
//			m_q.push(message);     // ������������������ӡ�
//		}
//		m_cond.notify_one();     // ����һ������ǰ���������������̡߳�
//	}
//
//	void outcache()       // �������߳���������
//	{
//		while (true)
//		{
//			string message;
//			{
//				// �ѻ�����ת����unique_lock<mutex>�������������
//				unique_lock<mutex> lock(m_mutex);
//
//				while (m_q.empty())    // ������пգ�����ѭ��������ֱ�Ӵ������ݡ�������ѭ����������if
//					m_cond.wait(lock);  // �ȴ������ߵĻ����źš�
//
//				// ����Ԫ�س��ӡ�
//				message = m_q.front();  m_q.pop();
//			}
//			// ������ӵ����ݣ����������ѵ�����
//			this_thread::sleep_for(chrono::milliseconds(1));   // ���账��������Ҫ1���롣
//			cout << "�̣߳�" << this_thread::get_id() << "��" << message << endl;
//		}
//	}
//};
//
//int main()
//{
//	AA aa;
//
//	thread t1(&AA::outcache, &aa);     // �����������߳�t1��
//	thread t2(&AA::outcache, &aa);     // �����������߳�t2��
//	thread t3(&AA::outcache, &aa);     // �����������߳�t3��
//
//	this_thread::sleep_for(chrono::seconds(2));    // ����2�롣
//	aa.incache(3);      // ����3�����ݡ�
//
//	this_thread::sleep_for(chrono::seconds(3));    // ����3�롣
//	aa.incache(5);      // ����5�����ݡ�
//
//	t1.join();   // �������̵߳���Դ��
//	t2.join();
//	t3.join();
//}



class BB
{
	mutex mtx; //������
	queue<string, deque<string>> que;  //������У� <�������ͣ��ײ�����>
	condition_variable c_var;  //��������

public:
	void generator(int num)  //������
	{
		lock_guard<mutex> lock(mtx);  //�������
		for (int j = 0; j < num; j++)
		{
			static int bh = 0;
			string message = to_string(bh++) + "�ų�Ů";
			que.push(message);
			cout << "ð�������񷢷ţ���Ҫ��ɵ������ţ�" << bh << endl;
		}

		c_var.notify_all();  //�����߳�
	}

	void cost()//������
	{
		while (true)// ����ѭ����һֱ�ڵȴ�������
		{
			string message;

			unique_lock<mutex> lock(mtx);  // ��Ϊ����wait�Ĵ��ڣ��������е��̶߳����Լ����ɹ����������ں���⿪
			
			//���������������������˯��1Сʱ��wait�����У���ô�����ֻ��һ���߳���������ɹ�
			//this_thread::sleep_for(chrono::hours(1));  
			while (que.empty())
			{
				c_var.wait(lock);  //1���ѻ������⿪���ͷŹ�����Դ  2�������ȴ�������  3�����Ѻ�����
			}

			message = que.front();
			que.pop();
			cout << "ð����" << this_thread::get_id() << "�Ž������񣬿�ʼִ�����񡭡�" << endl;
			lock.unlock();  //�ֶ�����������ռ����Դʱ�䡣���߿���ʹ��{}�����������uniqe_lock�Զ�����
						
			//�����ļ�
			this_thread::sleep_for(chrono::milliseconds(1));
		}
	}

};

int model()
{
	BB bb;
	thread t1(&BB::cost, &bb);
	thread t2(&BB::cost, &bb);
	thread t3(&BB::cost, &bb);

	this_thread::sleep_for(chrono::seconds(2));
	bb.generator(2);

	this_thread::sleep_for(chrono::seconds(2));

	bb.generator(4);

	this_thread::sleep_for(chrono::seconds(3));

	//��Ϊ�������߳�������ѭ�������Գ�����Զ����ֹͣ
	t1.join();
	t2.join();
	t3.join();
	return 0;
}

