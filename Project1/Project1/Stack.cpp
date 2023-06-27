//# include <iostream>
//# include <string>
//
//using namespace std;
//
//template <class T>
//class Stack
//{
//private:
//	T *items;
//	int stacksize;
//	int top;
//
//public:
//	Stack(int size) :stacksize(size), top(0) 
//	{
//		items = new T[stacksize];
//	}
//
//	bool isempty() const
//	{
//		return top == 0;
//	}
//	bool isfull() const
//	{
//		return top == stacksize;
//	}
//
//	bool push(T &item)
//	{
//		items[top] = item;
//		top++;
//		return true;
//	}
//
//	bool pop(T &item)
//	{
//		top--;
//		item = items[top];
//		return true;
//	}
//};
//
//int main()
//{
//	Stack<int> exam(10);
//	int item;
//	for (int i = 0; i < 10; i++)
//	{
//		item = i+48;
//		exam.push(item);
//	}
//
//	while (exam.isempty() == false)
//	{
//		exam.pop(item);
//		
//		cout <<"item = "<< item << endl;
//	}
//	
//	return 0;
//
//}

