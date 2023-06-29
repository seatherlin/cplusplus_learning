
//此段代码在VS2017中会报错

//#include <iostream>         // 包含头文件。
//#include <memory>
//#include<functional>
//
//using namespace std;        // 指定缺省的命名空间。
//
//class Hero                        // 英雄基类
//{
//public:
//	function<void()> m_callback;
//
//	template<typename Fun, typename ...Args>
//	void callback(Fun&& fun, Args&& ...args)
//	{
//		m_callback = bind(forward<Fun>(fun), forward<Args>(args)...);
//	}
//
//	void skill1() { m_callback(); }
//
//};
//
//class XS :public Hero       // 西施派生类
//{
//public:
//	void skill1() { cout << "西施释放了一技能。\n"; }
//
//};
//
//class HX :public Hero       // 韩信派生类
//{
//public:
//	void skill1() { cout << "韩信释放了一技能。\n"; }
//
//};
//
//class LB :public Hero       // 李白派生类
//{
//public:
//	void skill1() { cout << "李白释放了一技能。\n"; }
//
//};
//
//int main()
////void duotai()
//{
//	// 根据用户选择的英雄，施展一技能、二技能和大招。
//	int id = 0;     // 英雄的id。
//	cout << "请输入英雄（1-西施；2-韩信；3-李白。）：";
//	cin >> id;
//
//	// 创建基类指针，让它指向派生类对象，用基类指针调用派生类的成员函数。
//	Hero* ptr = nullptr;
//	//unique_ptr<Hero> ptr;
//	if (id == 1)
//	{             // 1-西施
//		ptr = new XS;
//		ptr->callback(&XS::skill1, static_cast<XS*>(ptr));
//		//ptr = unique_ptr<XS>(new XS);
//	}
//	else if (id == 2)
//	{      // 2-韩信
//		ptr = new HX;
//		ptr->callback(&HX::skill1, static_cast<HX*>(ptr));
//		//ptr = unique_ptr<HX>(new HX);
//	}
//	else if (id == 3)
//	{      // 3-李白
//		ptr = new LB;
//		ptr->callback(&LB::skill1, static_cast<LB*>(ptr));
//		//ptr = unique_ptr<LB>(new LB);
//	}
//
//	if (ptr != nullptr)
//	{
//		ptr->skill1();
//		delete ptr;
//	}
//
//	return 0;
//}
