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

#include <iostream>         // ����ͷ�ļ���
#include <memory>


using namespace std;        // ָ��ȱʡ�������ռ䡣

class Hero                        // Ӣ�ۻ���
{
public:
	int viability;      // ����������
	int attack;         // �����˺���
	virtual void skill1() { cout << "Ӣ���ͷ���һ���ܡ�\n"; }
	virtual void skill2() { cout << "Ӣ���ͷ��˶����ܡ�\n"; }
	virtual void uskill() { cout << "Ӣ���ͷ��˴���С�\n"; }
};

class XS :public Hero       // ��ʩ������
{
public:
	void skill1() { cout << "��ʩ�ͷ���һ���ܡ�\n"; }
	void skill2() { cout << "��ʩ�ͷ��˶����ܡ�\n"; }
	void uskill() { cout << "��ʩ�ͷ��˴��С�\n"; }
};

class HX :public Hero       // ����������
{
public:
	void skill1() { cout << "�����ͷ���һ���ܡ�\n"; }
	void skill2() { cout << "�����ͷ��˶����ܡ�\n"; }
	void uskill() { cout << "�����ͷ��˴��С�\n"; }
};

class LB :public Hero       // ���������
{
public:
	void skill1() { cout << "����ͷ���һ���ܡ�\n"; }
	void skill2() { cout << "����ͷ��˶����ܡ�\n"; }
	void uskill() { cout << "����ͷ��˴��С�\n"; }
};

//int main()
void duotai()
{
	// �����û�ѡ���Ӣ�ۣ�ʩչһ���ܡ������ܺʹ��С�
	int id = 0;     // Ӣ�۵�id��
	cout << "������Ӣ�ۣ�1-��ʩ��2-���ţ�3-��ס�����";
	cin >> id;

	// ��������ָ�룬����ָ������������û���ָ�����������ĳ�Ա������
	//Hero* ptr = nullptr;
	unique_ptr<Hero> ptr;
	if (id == 1) 
	{             // 1-��ʩ
		//ptr = new XS;
		ptr =unique_ptr<XS> (new XS);
	}
	else if (id == 2) 
	{      // 2-����
		//ptr = new HX;
		ptr = unique_ptr<HX>(new HX);
	}
	else if (id == 3) 
	{      // 3-���
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

