#include<iostream>
#include<string>
#include<thread>
#include<condition_variable>
#include<queue>
#include<deque>
#include<mutex>
#include<functional>

using namespace std;

void show(const string& message)
{  // ����ҵ�����ͨ����
	cout << "�������ݣ�" << message << endl;
}

struct Work
{  // ����ҵ�����
	void show(const string& message)
	{
		cout << "���������ݣ�" << message << endl;
	}
};

class Model
{
private:
	queue<string, deque<string>> que;
	condition_variable a_var;
	mutex mtx;
	function<void(const string &)> m_callback;  //�ص�����

public:
	template<typename Fun, typename ...Args>
	void callback(Fun&& fun, Args&& ...args)
	{
		m_callback = bind(forward<Fun>(fun), forward<Args>(args)..., std::placeholders::_1);
		//bindǰ���������������������ں���������һ������Ϊ����ɵ��ö���Ĳ���
	}

	void generator(int num)
	{
		lock_guard<mutex> l_guard(mtx);
		for (int i = 0; i < num; i++)
		{
			string message = "���յ���" + to_string(i);
			message = message + "�����񣬿�ʼ��������";
			cout << message << endl;
			que.push(message);
		}
		a_var.notify_all();
	}

	void adventurer()
	{
		while (true)
		{
			unique_lock<mutex> u_lock(mtx);

			while (que.empty())
			{
				a_var.wait(u_lock);
			}

			string message = que.front(); que.pop();
			cout << "ð����" << this_thread::get_id() << "�������񡭡���ʼִ�С�" << endl;
			//this_thread::sleep_for(chrono::seconds(1));
			u_lock.unlock();

			if (m_callback)  m_callback(message);
		}
	}
};

int call_back_test()
{
	Model model;
	Work work;
	//model.callback(show); //���ｫ��ͨ����showע��Ϊ�ص�����
	model.callback(&Work::show, &work);  //�����ں���showע��Ϊ�ص�����

	thread t1(&Model::adventurer, &model);
	thread t2(&Model::adventurer, &model);
	thread t3(&Model::adventurer, &model);

	model.generator(3);

	this_thread::sleep_for(chrono::seconds(2));

	model.generator(4);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}