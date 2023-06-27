#include <iostream>
using namespace std;

class AA
{
public:
	int* m_data = nullptr;  // ���ݳ�Ա��ָ�������Դ��ָ�롣

	AA() = default;             // ����Ĭ�Ϲ��캯����

	void alloc() 
	{                // �����ݳ�Աm_data�����ڴ档
		m_data = new int;                       // �����ڴ档
		memset(m_data, 0, sizeof(int));   // ��ʼ���ѷ�����ڴ档
	}

	AA(const AA& a)
	{     // �������캯����
		cout << "�����˿������캯����\n";            // ��ʾ�Լ������õ���־��
		if (m_data == nullptr) alloc();                     // ���û�з����ڴ棬�ͷ��䡣
		memcpy(m_data, a.m_data, sizeof(int));     // �����ݴ�Դ�����п���������
	}

	AA(AA&& a) {     // �ƶ����캯����
		cout << "�������ƶ����캯����\n";            // ��ʾ�Լ������õ���־��
		if (m_data != nullptr) delete m_data;         // ����ѷ����ڴ棬���ͷŵ���
		m_data = a.m_data;                                   // ����Դ��Դ������ת�ƹ�����
		a.m_data = nullptr;                                    // ��Դ�����е�ָ���ÿա�
	}

	AA& operator=(const AA& a) { // ��ֵ������
		cout << "�����˸�ֵ������\n";                   // ��ʾ�Լ������õ���־��
		if (this == &a)   return *this;                      // �������Ҹ�ֵ��
		if (m_data == nullptr) alloc();                     // ���û�з����ڴ棬�ͷ��䡣
		memcpy(m_data, a.m_data, sizeof(int));    // �����ݴ�Դ�����п���������
		return *this;
	}

	AA& operator=(AA&& a) { // �ƶ���ֵ������
		cout << "�������ƶ���ֵ������\n";            // ��ʾ�Լ������õ���־��
		if (this == &a)   return *this;                      // �������Ҹ�ֵ��
		if (m_data != nullptr) delete m_data;         // ����ѷ����ڴ棬���ͷŵ���
		m_data = a.m_data;                                   // ����Դ��Դ������ת�ƹ�����
		a.m_data = nullptr;                                    // ��Դ�����е�ָ���ÿա�
		return *this;
	}

	~AA() {                 // ����������
		if (m_data != nullptr) {
			delete m_data; m_data = nullptr;
		}
	}
};

int xian()
{
	AA a1;                  // ��������a1��
	a1.alloc();             // ���������Դ��
	*a1.m_data = 3;   // �������ڴ渳ֵ��
	cout << "a1.m_data=" << *a1.m_data << endl;

	AA a2 = a1;         // �����ÿ������캯����
	cout << "a2.m_data=" << *a2.m_data << endl;

	AA a3;
	a3 = a1;              // �����ø�ֵ������
	cout << "a3.m_data=" << *a3.m_data << endl;

	auto f = [] { AA aa; aa.alloc(); *aa.m_data = 8; return aa; };   // ����AA������lambda������
	AA a4 = f();                // lambda����������ʱ��������ֵ���������ƶ����캯����
	cout << "a4.m_data=" << *a4.m_data << endl;

	AA a6;
	a6 = f();              // lambda����������ʱ��������ֵ���������ƶ���ֵ������
	cout << "a6.m_data=" << *a6.m_data << endl;

	return 0;
}
