#include <iostream>
#include <functional>
#include<string>

using namespace std;

// ��ͨ����
void show(int bh, const string& message) {
	cout << "�װ���" << bh << "��" << message << endl;
}

struct AA	// �����о�̬��Ա������
{
	static void show(int bh, const string& message) {
		cout << "�װ���" << bh << "��" << message << endl;
	}
}; 

struct BB	// �º�����
{
	void operator()(int bh, const string& message) {
		cout << "�װ���" << bh << "��" << message << endl;
	}
};

struct CC	// ��������ͨ��Ա������
{
	void show(int bh, const string& message) {
		cout << "�װ���" << bh << "��" << message << endl;
	}
};

struct DD		// ���Ա�ת��Ϊ��ͨ����ָ����ࡣ
{
	using Fun = void(*)(int, const string&);    // ����ָ��ı�����
	operator Fun() {
		return show;	// ������ͨ����show�ĵ�ַ��
	}
};

int main()
{
	using Fun = void(int, const string&);  // �������͵ı�����

	// ��ͨ������
	void(*fp1)(int, const string&) = show;	// ��������ָ�룬ָ��������
	fp1(1, "����һֻɵɵ��");						// �ú���ָ�������ͨ������
	function<void(int, const string&)> fn1 = show;    // ��װ��ͨȫ�ֺ���show��
	fn1(1, "����һֻɵɵ��");										// ��function���������ͨȫ�ֺ���show��

	// ��ľ�̬��Ա������
	void(*fp3)(int, const string&) = AA::show;	// �ú���ָ��ָ����ľ�̬��Ա������
	fp3(2, "����һֻɵɵ��");							// �ú���ָ�������ľ�̬��Ա������
	function<void(int, const string&)> fn3 = AA::show;		// ��װ��ľ�̬��Ա������
	fn3(2, "����һֻɵɵ��");												// ��function���������ľ�̬��Ա������

	// �º�����
	BB bb;
	bb(3, "����һֻɵɵ��");		// �÷º���������÷º�����
	function<void(int, const string&)> fn4 = BB();		// ��װ�º�����
	fn4(3, "����һֻɵɵ��");										// ��function������÷º�����

	// ����lambda����
	auto lb = [](int bh, const string& message) {
		cout << "�װ���" << bh << "��" << message << endl;
	};
	lb(4, "����һֻɵɵ��");          // ����lambda������
	function<void(int, const string&)> fn5 = lb;			// ��װlamba������
	fn5(4, "����һֻɵɵ��");										// ��function�������lamba������

	// ��ķǾ�̬��Ա������
	CC cc;
	void (CC:: * fp11)(int, const string&) = &CC::show;		// �������Ա������ָ�롣
	(cc.*fp11)(5, "����һֻɵɵ��");									// �����Ա������ָ�������ĳ�Ա������
	function<void(CC&, int, const string&)> fn11 = &CC::show;	// ��װ��Ա������
	fn11(cc, 5, "����һֻɵɵ��");											// ��function������ó�Ա������

	// ���Ա�ת��Ϊ����ָ��������
	DD dd;

	dd(6, "����һֻɵɵ��");						// �ÿ��Ա�ת��Ϊ����ָ�������������ͨ������
	function<void(int, const string&)> fn12 = dd;			// ��װ���Ա�ת��Ϊ����ָ����ࡣ
	fn12(6, "����һֻɵɵ��");										// ��function�����������

	function<void(int, const string&)> fx = dd;
	try {
		if (fx) fx(6, "����һֻɵɵ��");
	}
	catch (std::bad_function_call e) {
		cout << "�׳���std::bad_function_call�쳣��";
	}


}
