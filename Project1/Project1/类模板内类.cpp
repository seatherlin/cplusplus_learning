//#include<iostream>
//#include<string>
//
//using namespace std;
//
////��˾ģ����
//template <class T1, class T2>
//class Company
//{
//public:
//	T1 company_name;
//	T2 company_stress;
//	Company(T1 name, T2 stress) :company_name(name), company_stress(stress) {}
//
//	//Ա������ģ����
//	template<class T3, class T4>
//	class Staff
//	{
//	public:
//		T3 staff_name;
//		T4 staff_department;
//		int staff_number;
//		//Staff(T3 name, T4 department, T5 snumber) :staff_name(name), staff_department(department), staff_number(number) {}
//
//		void show() const //��ʾԱ������
//		{ 
//			cout << "Ա��������" << staff_name << "\nԱ�����ţ�" << staff_department << "\nԱ�����ţ�" << staff_number << endl;
//		}
//
//	};
//	Staff<T1, T1> staff; //�������ڴˡ�ʵ������һ������
//
//	//�������캯��
//	Company(const Company &a)
//	{
//		company_name = a.company_name;
//		company_stress = a.company_stress;
//		staff.staff_name = a.staff.staff_name;
//		staff.staff_department = a.staff.staff_department;
//		staff.staff_number = a.staff.staff_number;
//	}
//
//	//��˾���
//	//template<typename T6>
//	void company_profile()
//	{
//		cout << "��˾����Ϊ:" << company_name << "\n��˾��ַΪ��" << company_stress << "\n\nԱ����������:" << endl;
//		staff.show();
//	}
//};
//
//int main()
//{
//	Company<string, string> company("722��", "������");
//	company.staff.staff_name = "lxh";
//	company.staff.staff_department = "�¼���";
//	company.staff.staff_number = 83538;
//
//	company.company_profile();
//
//	Company<string, string> b(company);
//	cout << "\n\n";
//	b.staff.staff_name = "lcw";
//	b.staff.staff_department = "������";
//	b.staff.staff_number = 83540;
//	b.company_profile();
//
//	cout << __cplusplus <<"\n"<<__TIME__<<"\n"<< __TIMESTAMP__<<endl;
//
//	return 0;
//}