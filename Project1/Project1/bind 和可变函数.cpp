#include<iostream>
#include<functional>
#include<string>

using namespace std;

void task1()
{
	cout << "ð���߽�ȡ���񡭡�" << endl;
}

void task2(int bh, string message)
{
	cout << "��" << bh << "��ð���߽�ȡ���񡭡�" << "���Ŀں��ǣ�" << message << endl;
}

class Adventurer
{
public:
	void task3(int bh, string message)
	{
		cout << "��" << bh << "��ð���߽�ȡ���񡭡�" << "���Ŀں��ǣ�" << message << endl;
	}
};

template<typename Fun, typename ...Args>
auto show(Fun&& fun, Args&& ...args) -> decltype(bind(forward<Fun>(fun), forward<Args>(args)...))
{
	auto f1 = bind(forward<Fun>(fun), forward<Args>(args)...);
	f1();
	cout << "������ϡ�" << endl;
	return f1;
}

int show_main()
{
	show(task1);
	show(task2, 1, "��һ�����ԣ�");
	Adventurer adventurer;
	show(&Adventurer::task3, &adventurer, 2, "һ���������");

	return 0;
}