//#include<iostream>
//
//using namespace std;
//
//template <class T>
//class vector
//{
//private:
//	T *items;
//	int length;
//public:
//	vector(int size) :length(size)
//	{
//		items = new T[length];
//	}
//
//	~vector()  //解构函数 
//	{
//		delete[]items; items = nullptr;
//	}
//
//	int size() const { return length; } //只读模式获取长度
//
//	//扩展数组长度
//	void resize(int newsize)
//	{
//		if (newsize < length) return; //新长度小于原长度不需要重新分配内存
//		int *newitems = new T[newsize];
//		for (int i = 0; i < length; i++) { newitems[i] = items[i]; }
//		delete[]items;
//		items = newitems;
//		length = newsize;
//	}
//
//	//重载操作符：下标[]
//	int &operator[](int ii)
//	{
//		if (ii >= length) resize(ii + 10);  //可以预先多分配10个内存，防止反复新建
//		return items[ii];
//	}
//};
//
//int main()
//{
//	vector<int> item(5);
//	for (int i = 0; i < item.size(); i++) { item[i] = i + 1;  cout << item[i] << endl; }
//
//	item.resize(10);
//	cout << item.size() << endl;
//	return 0;
//}