//#include<iostream>
//using namespace std;
//
//
//class Shape 
//{
//protected:
//	int width, height;
//public:
//	virtual int get_area() = 0;
//	/*Shape(int a = 0, int b = 0)
//	{
//		width = a;
//		height = b;
//	}*/
//	void set_width(int w)
//	{
//		width = w;
//	}
//	void set_height(int h)
//	{
//		height = h;
//	}
//	/*virtual int area()
//	{
//		cout << "Parent class area :" << endl;
//		return 0;
//	}*/
//};
//
//class Rec :public Shape 
//{
//public:
//	/*Rec(int a=0,int b=0):Shape(a,b){}*/
//	/*int area()
//	{
//		cout << "child class area:" << width * height << endl;
//		return width * height;
//	}*/
//	int get_area()
//	{
//		return width * height;
//	}
//};
//
//class Tri :public Shape
//{
//public:
//	/*Tri(int a = 0,int b=0):Shape(a,b){}
//	int area()
//	{
//		cout << "child class area:" << width * height / 2 <<endl;
//		return width * height / 2;
//	}*/
//
//	int get_area()
//	{
//		return width * height / 2;
//	}
//};
//
//int main() 
//{
//	Shape *shape;
//	Rec rec;
//	Tri tri;
//	int area;
//	rec.set_width(2); rec.set_height(3);
//	shape = &rec;
//	area = shape->get_area();
//	cout << area << endl;
//
//
//	tri.set_width(7); tri.set_height(10);
//	shape = &tri;
//	area = shape->get_area();
//	cout << area << endl;
//
//	return 0;
//}

#include <iostream>         // 包含头文件。
#include <memory>


using namespace std;        // 指定缺省的命名空间。

class Hero                        // 英雄基类
{
public:
	int viability;      // 生存能力。
	int attack;         // 攻击伤害。
	virtual void skill1() { cout << "英雄释放了一技能。\n"; }
	virtual void skill2() { cout << "英雄释放了二技能。\n"; }
	virtual void uskill() { cout << "英雄释放了大绝招。\n"; }
};

class XS :public Hero       // 西施派生类
{
public:
	void skill1() { cout << "西施释放了一技能。\n"; }
	void skill2() { cout << "西施释放了二技能。\n"; }
	void uskill() { cout << "西施释放了大招。\n"; }
};

class HX :public Hero       // 韩信派生类
{
public:
	void skill1() { cout << "韩信释放了一技能。\n"; }
	void skill2() { cout << "韩信释放了二技能。\n"; }
	void uskill() { cout << "韩信释放了大招。\n"; }
};

class LB :public Hero       // 李白派生类
{
public:
	void skill1() { cout << "李白释放了一技能。\n"; }
	void skill2() { cout << "李白释放了二技能。\n"; }
	void uskill() { cout << "李白释放了大招。\n"; }
};

//int main()
void duotai()
{
	// 根据用户选择的英雄，施展一技能、二技能和大招。
	int id = 0;     // 英雄的id。
	cout << "请输入英雄（1-西施；2-韩信；3-李白。）：";
	cin >> id;

	// 创建基类指针，让它指向派生类对象，用基类指针调用派生类的成员函数。
	//Hero* ptr = nullptr;
	unique_ptr<Hero> ptr;
	if (id == 1) 
	{             // 1-西施
		//ptr = new XS;
		ptr =unique_ptr<XS> (new XS);
	}
	else if (id == 2) 
	{      // 2-韩信
		//ptr = new HX;
		ptr = unique_ptr<HX>(new HX);
	}
	else if (id == 3) 
	{      // 3-李白
		//ptr = new LB;
		ptr = unique_ptr<LB>(new LB);
	}

	if (ptr != nullptr) 
	{
		ptr->skill1();
		ptr->skill2();
		ptr->uskill();
		//delete ptr;
	}
}

