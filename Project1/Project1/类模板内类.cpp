//#include<iostream>
//#include<string>
//
//using namespace std;
//
////公司模板类
//template <class T1, class T2>
//class Company
//{
//public:
//	T1 company_name;
//	T2 company_stress;
//	Company(T1 name, T2 stress) :company_name(name), company_stress(stress) {}
//
//	//员工资料模板类
//	template<class T3, class T4>
//	class Staff
//	{
//	public:
//		T3 staff_name;
//		T4 staff_department;
//		int staff_number;
//		//Staff(T3 name, T4 department, T5 snumber) :staff_name(name), staff_department(department), staff_number(number) {}
//
//		void show() const //显示员工资料
//		{ 
//			cout << "员工姓名：" << staff_name << "\n员工部门：" << staff_department << "\n员工工号：" << staff_number << endl;
//		}
//
//	};
//	Staff<T1, T1> staff; //必须先在此“实例化”一个对象
//
//	//拷贝构造函数
//	Company(const Company &a)
//	{
//		company_name = a.company_name;
//		company_stress = a.company_stress;
//		staff.staff_name = a.staff.staff_name;
//		staff.staff_department = a.staff.staff_department;
//		staff.staff_number = a.staff.staff_number;
//	}
//
//	//公司简介
//	//template<typename T6>
//	void company_profile()
//	{
//		cout << "公司名称为:" << company_name << "\n公司地址为：" << company_stress << "\n\n员工资料如下:" << endl;
//		staff.show();
//	}
//};
//
//int main()
//{
//	Company<string, string> company("722所", "江夏区");
//	company.staff.staff_name = "lxh";
//	company.staff.staff_department = "新技术";
//	company.staff.staff_number = 83538;
//
//	company.company_profile();
//
//	Company<string, string> b(company);
//	cout << "\n\n";
//	b.staff.staff_name = "lcw";
//	b.staff.staff_department = "质量部";
//	b.staff.staff_number = 83540;
//	b.company_profile();
//
//	cout << __cplusplus <<"\n"<<__TIME__<<"\n"<< __TIMESTAMP__<<endl;
//
//	return 0;
//}