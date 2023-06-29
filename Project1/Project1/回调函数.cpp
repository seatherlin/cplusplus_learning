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
{  // 处理业务的普通函数
	cout << "处理数据：" << message << endl;
}

struct Work
{  // 处理业务的类
	void show(const string& message)
	{
		cout << "处理表白数据：" << message << endl;
	}
};

class Model
{
private:
	queue<string, deque<string>> que;
	condition_variable a_var;
	mutex mtx;
	function<void(const string &)> m_callback;  //回调函数

public:
	template<typename Fun, typename ...Args>
	void callback(Fun&& fun, Args&& ...args)
	{
		m_callback = bind(forward<Fun>(fun), forward<Args>(args)..., std::placeholders::_1);
		//bind前面俩参数代表函数或者类内函数，后面一个参数为传入可调用对象的参数
	}

	void generator(int num)
	{
		lock_guard<mutex> l_guard(mtx);
		for (int i = 0; i < num; i++)
		{
			string message = "接收到第" + to_string(i);
			message = message + "号任务，开始发布……";
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
			cout << "冒险者" << this_thread::get_id() << "接受任务……开始执行。" << endl;
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
	//model.callback(show); //这里将普通函数show注册为回调函数
	model.callback(&Work::show, &work);  //将类内函数show注册为回调函数

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