//#include <iostream>
//#include<thread>
//#include<string>
//
//#include<chrono>
//
//using namespace std;
//
//template<class T1, class T2>
//class My_class
//{
//public:
//	void function(T1 i, T2 str)
//	{
//		cout << "No." << i <<"  "<< str << endl;
//		this_thread::sleep_for(chrono::seconds(2));
//		
//		cout << "线程为：" << this_thread::get_id() << endl;
//
//		
//	}
//};
//
//
//int main()
//{
//	My_class<int, string> my_class;
//	thread t1(&My_class<int, string>::function, &my_class, 2, "hello!");
//
//	t1.join();
//
//}

//#include<iostream>
//#include<mutex>
//#include<string>
//
//using namespace std;
//
//mutex mtx;
//
//
//void func(int bh, const string& str)
//{
//	for (int ii = 0; ii < 10; ii++)
//	{
//		mtx.lock();
//		cout << "no" << ii << "次，表白：亲爱的" << bh << "号" << str << endl;
//		mtx.unlock();
//		this_thread::sleep_for(chrono::seconds(1));
//	}
//}


//int main()
//{
//	thread t1(func, 2, "nihao");
//	
//	t1.join();
//	return 0;
//
//
//}