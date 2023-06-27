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
//	~vector()  //�⹹���� 
//	{
//		delete[]items; items = nullptr;
//	}
//
//	int size() const { return length; } //ֻ��ģʽ��ȡ����
//
//	//��չ���鳤��
//	void resize(int newsize)
//	{
//		if (newsize < length) return; //�³���С��ԭ���Ȳ���Ҫ���·����ڴ�
//		int *newitems = new T[newsize];
//		for (int i = 0; i < length; i++) { newitems[i] = items[i]; }
//		delete[]items;
//		items = newitems;
//		length = newsize;
//	}
//
//	//���ز��������±�[]
//	int &operator[](int ii)
//	{
//		if (ii >= length) resize(ii + 10);  //����Ԥ�ȶ����10���ڴ棬��ֹ�����½�
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