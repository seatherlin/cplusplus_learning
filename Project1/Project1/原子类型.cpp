#include<iostream>
#include<atomic>
#include<thread>

using namespace std;

atomic_int aa = 0;

void func()
{
	for (int i = 0; i < 1000000; i++)
	{
		aa++;
	}
}


int yuan_zi()
{
	thread t1(func);
	thread t2(func);

	t1.join();
	t2.join();

	cout << "aa=" << aa << endl;

	return 0;
}