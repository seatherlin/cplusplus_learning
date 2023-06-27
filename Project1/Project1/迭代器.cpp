#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

template<class T> class AA 
{	
public:
	T name;
	AA(T new_name) :name(new_name) { cout << "调用构造函数\n"; }

	AA(const AA &a) { name = a.name; cout << "调用拷贝构造函数\n";}

	~AA() { cout << "调用析构函数\n"; }
};

template <typename T>
pair<int, AA<T>> functions(int &number, AA<T> &myname)
{

	pair<int, AA<T>> clock(number, myname);
	return clock;
}

//int main()
//{
//	vector<int> a1 = { 1,2,3,4,5 };
//	vector<pair<int, AA<string>>> v1;
//
//	AA<string> myname;
//	myname.name = "lixiaohan";
//
//	for (auto i : a1)
//	{
//		v1.push_back(functions<string>(i, myname));
//		cout << v1[i-1].first << endl;
//		cout << v1[i-1].second.name << endl;
//	}
//	return 0;
//}


void iter()
{
	//vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> v2(v1.cbegin() + 2, v1.cend() - 2);

	//auto iter = v2.insert(v2.cbegin() + 2, 15);

	//auto iter2 = v1.insert(v1.cbegin() + 3, v2.cbegin(), v2.cend() - 1);

	//for (auto ii = v1.cbegin(); ii != v1.cend(); ii++)//基于迭代器的循环
	//{
	//	cout << *ii << "  ";
	//}
	//cout << endl;
	//
	//for (int val : v2)//基于范围的循环
	//{
	//	cout << val << endl;
	//}
	vector<AA<string>> aa;
	cout << "1---------------:\n";
	aa.emplace_back(AA<string>("hello"));
	cout << "2---------------:\n";
	aa.emplace_back(AA<string>("hello")); //先构造新的空间为2的内存空间，构造新的类“nihao”，然后将之前的类拷贝过来，再释放之前的空间
	cout << "3---------------:\n";
	aa.emplace_back(AA<string>("hello"));

	for (const auto &iter : aa) //迭代器
	{
		cout << iter.name << "\n";
	}
	cout << endl;

	/*fstream fout;
	fout.open("");*/


	//return 0;
}