#include <iostream>

using namespace std;

class Box
{
public:
	static int objectCount;
	// ���캯������
	Box(double l = 2.0, double b = 2.0, double h = 2.0)
	{
		cout << "Constructor called." << endl;
		length = l;
		breadth = b;
		height = h;
		// ÿ�δ�������ʱ���� 1
		objectCount++;
	}
	double Volume()
	{
		return length * breadth * height;
	}
	static int getCount()
	{
		return Box::objectCount;
	}
private:
	double length;     // ����
	double breadth;    // ���
	double height;     // �߶�
};

// ��ʼ���� Box �ľ�̬��Ա
int Box::objectCount = 0;

//
//int main(void)
//{
//
//	// �ڴ�������֮ǰ������������
//	cout << "Inital Stage Count: " << Box::getCount() << endl;
//
//	Box Box1(3.3, 1.2, 1.5);    // ���� box1
//	Box Box2(8.5, 6.0, 2.0);    // ���� box2
//
//	// �ڴ�������֮��������������
//	cout << "Final Stage Count: " << Box::getCount() << endl;
//
//	return 0;
//}