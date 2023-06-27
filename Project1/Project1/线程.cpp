//#include <iostream>
//#include <thread>
//#include <windows.h>         // Sleep()函数需要这个头文件。
//#include<string>
//
//using namespace std;
//
////普通函数
//void func(int bh, const string &str)
//{
//	for (int i = 1; i < 10; i++)
//	{
//		cout << "第" << i << "次，表白" << str << endl;
//
//		Sleep(1000);//休眠1秒
//	}
//}
//
//
//int xiancheng_()
//{
//	thread t1(func, 3, "strffff");
//	thread t2(func, 8, "sddddddddd");
//	cout << "任务开始。\n";
//	thread t3 = move(t2);
//	for (int ii = 0; ii < 10; ii++)
//	{
//		cout << "任务执行中……\n";
//		Sleep(1000);
//	} 
//	cout << "任务完成。\n";
//
//	t1.join();
//	t3.join();
//	return 0;
//}