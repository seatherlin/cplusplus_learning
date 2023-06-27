#include<iostream>
#include<string>
#include<vector>

using namespace std;

//表白函数func
template <typename T>
bool func(const T &a)
{
	if (a == 3)
	{
		cout << "函数表白：" << a << endl;
		return true;
	}
	return false;
	
}

//表白类
template<class T>
class Biaobai
{
public:
	bool operator()(const T&a)
	{
		if (a == 3)
		{
			cout << "函数表白：" << a << endl;
			return true;
		}
		return false;
	}

};

template <typename T1, typename T2>
T1 findif(const T1 first, const T1 last, T2 func)
{
	T1 a = last;
	for (auto iter = first; iter != last; iter++)
	{
		if (func(*iter) == true) a = iter;
	}
	if (a == last) return last; 
	return a;
	
}

void for_each_like()
{
	vector<int> a1 = { 1,2,3,4,5,3,7,3,9 };

	auto it1 = findif(a1.begin(), a1.end(), func<int>);

	if (it1 == a1.end()) cout << "查找失败" << endl;
	
	Biaobai<int> aa;
	auto it2 = findif(a1.begin(), a1.end(), aa);
	if (it2 == a1.end()) cout << "查找失败" << endl;

}
