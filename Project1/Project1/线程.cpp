//#include <iostream>
//#include <thread>
//#include <windows.h>         // Sleep()������Ҫ���ͷ�ļ���
//#include<string>
//
//using namespace std;
//
////��ͨ����
//void func(int bh, const string &str)
//{
//	for (int i = 1; i < 10; i++)
//	{
//		cout << "��" << i << "�Σ����" << str << endl;
//
//		Sleep(1000);//����1��
//	}
//}
//
//
//int xiancheng_()
//{
//	thread t1(func, 3, "strffff");
//	thread t2(func, 8, "sddddddddd");
//	cout << "����ʼ��\n";
//	thread t3 = move(t2);
//	for (int ii = 0; ii < 10; ii++)
//	{
//		cout << "����ִ���С���\n";
//		Sleep(1000);
//	} 
//	cout << "������ɡ�\n";
//
//	t1.join();
//	t3.join();
//	return 0;
//}