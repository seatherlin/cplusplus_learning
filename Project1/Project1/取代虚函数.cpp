
//�˶δ�����VS2017�лᱨ��

//#include <iostream>         // ����ͷ�ļ���
//#include <memory>
//#include<functional>
//
//using namespace std;        // ָ��ȱʡ�������ռ䡣
//
//class Hero                        // Ӣ�ۻ���
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
//class XS :public Hero       // ��ʩ������
//{
//public:
//	void skill1() { cout << "��ʩ�ͷ���һ���ܡ�\n"; }
//
//};
//
//class HX :public Hero       // ����������
//{
//public:
//	void skill1() { cout << "�����ͷ���һ���ܡ�\n"; }
//
//};
//
//class LB :public Hero       // ���������
//{
//public:
//	void skill1() { cout << "����ͷ���һ���ܡ�\n"; }
//
//};
//
//int main()
////void duotai()
//{
//	// �����û�ѡ���Ӣ�ۣ�ʩչһ���ܡ������ܺʹ��С�
//	int id = 0;     // Ӣ�۵�id��
//	cout << "������Ӣ�ۣ�1-��ʩ��2-���ţ�3-��ס�����";
//	cin >> id;
//
//	// ��������ָ�룬����ָ������������û���ָ�����������ĳ�Ա������
//	Hero* ptr = nullptr;
//	//unique_ptr<Hero> ptr;
//	if (id == 1)
//	{             // 1-��ʩ
//		ptr = new XS;
//		ptr->callback(&XS::skill1, static_cast<XS*>(ptr));
//		//ptr = unique_ptr<XS>(new XS);
//	}
//	else if (id == 2)
//	{      // 2-����
//		ptr = new HX;
//		ptr->callback(&HX::skill1, static_cast<HX*>(ptr));
//		//ptr = unique_ptr<HX>(new HX);
//	}
//	else if (id == 3)
//	{      // 3-���
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
