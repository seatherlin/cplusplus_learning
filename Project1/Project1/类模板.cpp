//# include <iostream>
//
//using namespace std;
//
//template <class T>
//class vector
//{
//private:
//	T *items;
//	int length;
//
//public:
//	vector(int len) :length(len) { items = new T[length]; }
//
//	~vector() { delete[]items; items = nullptr; }
//
//	//÷ÿ‘ÿ∑˚∫≈[]
//	int &operator[](int ii)
//	{
//		return items[ii];
//	}
//
//	int size() const { return length; }
//
//	void resize(int new_len)
//	{
//		T *new_items = new T[new_len];
//		for (int i = 0; i < length; i++) { new_items[i] = items[i]; }
//		delete[]items;
//		items = new_items;
//		length = new_len;
//	}
//
//};
//
//
//int main()
//{
//	vector<int> a(10);
//	
//
//	return 0;
//}