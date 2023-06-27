#include<iostream>

using namespace std;

template<class T>
class AA
{
public:
	T m_a;

	AA(T c) :m_a(c){}
};

AA<int> get_temp()
{
	return AA<int>(2);
}
//
//int main()
//{
//	AA<int> &&aa = get_temp();
//	AA<int> c(3);
//	c.m_a = 4;
//	cout << c.m_a << endl;
//	aa.m_a = 3;
//	cout << aa.m_a << endl;
//
//	return 0;
//
//}

// Ϊ