#include<iostream>
#include<vector>
#include<memory>
#include<string>

using namespace std;

template<class T>
class AA
{
public:
	T n_name;
	AA(const T & name) :n_name(name){ cout << "���ù��캯��" << endl; }
	~AA() { cout << "������������" << endl; }
};

void smart_ptr()
{
	AA<string> *p = new AA<string>("mingzi");
	unique_ptr<AA<string>> pu2(p);
	unique_ptr<AA<string>>  pi(new AA<string>("����"));
	cout << (*pi).n_name << endl;

	cout << p << endl;
	cout << pu2 << endl;

}