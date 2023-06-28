#include<iostream>
#include<functional>
#include<string>

using namespace std;

void task1()
{
	cout << "冒险者接取任务……" << endl;
}

void task2(int bh, string message)
{
	cout << "第" << bh << "号冒险者接取任务……" << "他的口号是：" << message << endl;
}

class Adventurer
{
public:
	void task3(int bh, string message)
	{
		cout << "第" << bh << "号冒险者接取任务……" << "他的口号是：" << message << endl;
	}
};

template<typename Fun, typename ...Args>
auto show(Fun&& fun, Args&& ...args) -> decltype(bind(forward<Fun>(fun), forward<Args>(args)...))
{
	auto f1 = bind(forward<Fun>(fun), forward<Args>(args)...);
	f1();
	cout << "宣言完毕。" << endl;
	return f1;
}

int show_main()
{
	show(task1);
	show(task2, 1, "我一定可以！");
	Adventurer adventurer;
	show(&Adventurer::task3, &adventurer, 2, "一定完成任务！");

	return 0;
}