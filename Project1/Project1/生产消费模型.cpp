#include <iostream>
#include <string>
#include <thread>                      // 线程类头文件。
#include <mutex>                      // 互斥锁类的头文件。
#include <deque>                      // deque容器的头文件。
#include <queue>                      // queue容器的头文件。
#include <condition_variable>  // 条件变量的头文件。
using namespace std;
//class AA
//{
//	mutex m_mutex;                                    // 互斥锁。
//	condition_variable m_cond;                  // 条件变量。
//	queue<string, deque<string>> m_q;   // 缓存队列，底层容器用deque。
//public:
//	void incache(int num)     // 生产数据，num指定数据的个数。
//	{
//		lock_guard<mutex> lock(m_mutex);   // 申请加锁。
//		for (int ii = 0; ii < num; ii++)
//		{
//			static int bh = 1;           // 超女编号。
//			string message = to_string(bh++) + "号超女";    // 拼接出一个数据。
//			m_q.push(message);     // 把生产出来的数据入队。
//		}
//		m_cond.notify_one();     // 唤醒一个被当前条件变量阻塞的线程。
//	}
//
//	void outcache()       // 消费者线程任务函数。
//	{
//		while (true)
//		{
//			string message;
//			{
//				// 把互斥锁转换成unique_lock<mutex>，并申请加锁。
//				unique_lock<mutex> lock(m_mutex);
//
//				while (m_q.empty())    // 如果队列空，进入循环，否则直接处理数据。必须用循环，不能用if
//					m_cond.wait(lock);  // 等待生产者的唤醒信号。
//
//				// 数据元素出队。
//				message = m_q.front();  m_q.pop();
//			}
//			// 处理出队的数据（把数据消费掉）。
//			this_thread::sleep_for(chrono::milliseconds(1));   // 假设处理数据需要1毫秒。
//			cout << "线程：" << this_thread::get_id() << "，" << message << endl;
//		}
//	}
//};
//
//int main()
//{
//	AA aa;
//
//	thread t1(&AA::outcache, &aa);     // 创建消费者线程t1。
//	thread t2(&AA::outcache, &aa);     // 创建消费者线程t2。
//	thread t3(&AA::outcache, &aa);     // 创建消费者线程t3。
//
//	this_thread::sleep_for(chrono::seconds(2));    // 休眠2秒。
//	aa.incache(3);      // 生产3个数据。
//
//	this_thread::sleep_for(chrono::seconds(3));    // 休眠3秒。
//	aa.incache(5);      // 生产5个数据。
//
//	t1.join();   // 回收子线程的资源。
//	t2.join();
//	t3.join();
//}



class BB
{
	mutex mtx; //互斥锁
	queue<string, deque<string>> que;  //缓存队列， <数据类型，底层容器>
	condition_variable c_var;  //条件变量

public:
	void generator(int num)  //生产者
	{
		lock_guard<mutex> lock(mtx);  //申请加锁
		for (int j = 0; j < num; j++)
		{
			static int bh = 0;
			string message = to_string(bh++) + "号超女";
			que.push(message);
			cout << "冒险者任务发放，需要完成的任务编号：" << bh << endl;
		}

		c_var.notify_all();  //唤醒线程
	}

	void cost()//消费者
	{
		while (true)// 无限循环，一直在等待任务唤醒
		{
			string message;

			unique_lock<mutex> lock(mtx);  // 因为后面wait的存在，这里所有的线程都可以加锁成功，不过会在后面解开
			
			//假如启用下面代码在这里睡眠1小时，wait不运行，那么上面会只有一个线程申请加锁成功
			//this_thread::sleep_for(chrono::hours(1));  
			while (que.empty())
			{
				c_var.wait(lock);  //1、把互斥锁解开，释放公共资源  2、阻塞等待被唤醒  3、唤醒后会加锁
			}

			message = que.front();
			que.pop();
			cout << "冒险者" << this_thread::get_id() << "号接受任务，开始执行任务……" << endl;
			lock.unlock();  //手动解锁，减少占用资源时间。或者可以使用{}添加作用域，让uniqe_lock自动解锁
						
			//处理文件
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

	//因为消费者线程是无限循环，所以程序永远不会停止
	t1.join();
	t2.join();
	t3.join();
	return 0;
}

