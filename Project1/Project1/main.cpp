#include<iostream>

using namespace std;

class Line
{
public:
	Line(int len);//架构函数
	~Line();//析构函数
	Line(const Line &obj);
	int getlength(void);

private:
	int *ptr;
};

Line::Line(int len)
{
	ptr = new int;
	*ptr = len;
}

Line::~Line()
{
	delete ptr;
}


Line::Line(const Line &obj)
{
	ptr = new int;
	*ptr = *obj.ptr;
}

int Line::getlength()
{
	return *ptr;
}

void display(Line obj)
{
	cout << "length: " << obj.getlength()<< endl;
}


//int main()
//{
//	cout << "hello" << endl;
//
//	Line line(50);
//	display(line);
//	return 0;
//}