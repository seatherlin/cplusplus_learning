//#include <iostream>
//#include<string>
//#include <map>
//using  namespace std;
//
//class CGirl        // ��Ů�ࡣ
//{
//public:
//	string m_name;   // ��Ů������
//	int      m_age;       // ��Ů���䡣
//
//	/*CGirl() : m_age(0) {
//		cout << "Ĭ�Ϲ��캯����\n";
//	}*/
//	CGirl(const string name, const int age) : m_name(name), m_age(age) {
//		cout << "���������Ĺ��캯����\n";
//	}
//	CGirl(const CGirl & g) : m_name(g.m_name), m_age(g.m_age) {
//		cout << "�������캯����\n";
//	}
//};
//
//int main()
//{
//	//map<int, CGirl> mm;
//	//mm.insert     (pair<int, CGirl>(8, CGirl("����", 18)));                // һ�ι��캯�������ο������캯����
//	//mm.insert     (make_pair<int, CGirl>(8, CGirl("����", 18)));     // һ�ι��캯�������ο������캯����
//	//mm.emplace(pair<int, CGirl>(8, CGirl("����", 18)));                // һ�ι��캯�������ο������캯����
//	//mm.emplace(make_pair<int, CGirl>(8, CGirl("����", 18)));     // һ�ι��캯�������ο������캯����
//	//mm.emplace(8, CGirl("����", 18));                                             // һ�ι��캯����һ�ο������캯����
//	//mm.emplace(8, "����", 18);                                                        // ����
//	//mm.emplace(piecewise_construct, forward_as_tuple(8), forward_as_tuple("����", 18));  // һ�ι��캯����
//
//	//for (const auto& val : mm)
//	//	cout << val.first << "," << val.second.m_name << "," << val.second.m_name << "  ";
//	//cout << endl;
//
//	//return 0;
//
//	map<int, string> m;
//
//	// 1��void insert(initializer_list<pair<K,V>> il);  // ��ͳһ��ʼ���б��������в�����Ԫ�ء�
//	m.insert({ { 8,"����" }, { 3,"��ʩ" } });
//	m.insert({ pair<int,string>(1,"����"), make_pair<int,string>(7,"����"), {5,"����"} });
//	m.insert({ { 18,"����" }, { 3,"��ʩ" } });
//
//	// 2��pair<iterator,bool> insert(const pair<K,V> &value);  
//	// �������в���һ��Ԫ�أ�����ֵpair��first���Ѳ���Ԫ�صĵ�������second�ǲ�������
//	auto ret = m.insert(pair<int, string>(31, "����"));
//	if (ret.second == true) cout << "����ɹ���" << ret.first->first << "," << ret.first->second << endl;
//	else cout << "����ʧ�ܡ�\n";
//
//	// 3��void insert(iterator first, iterator last);  // �õ���������һ�������Ԫ�ء�
//
//	// 4��pair<iterator, bool> emplace(...);  
//	// �������¼�ֵ�������������Ϊ����ֱ�Ӵ��룬map������ֱ�ӹ���Ԫ�ء�
//	// ����ֵpair��first���Ѳ���Ԫ�صĵ�������second�ǲ�������
//	//auto ret1 = m.emplace(20, "����");
//	//if (ret1.second == true) cout << "����ɹ���" << ret1.first->first << "," << ret1.first->second << endl;
//	//else cout << "����ʧ�ܡ�\n";
//
//	//// 5��iterator emplace_hint(const_iterator pos, ...); 
//	//// �������4����������ͬ����һ��������ʾ����λ�ã��ò���ֻ�вο����壬�����ʾ��λ������ȷ�ģ�
//	//// �������������������ʾ��λ�ò���ȷ�����ܷ��������½������ǣ������Ƿ�ɹ���ò���Ԫ�ء�
//	//// �ò�������end()��begin()���ɹ������²���Ԫ�صĵ����������Ԫ���Ѿ����ڣ������ʧ�ܣ�������
//	//// ��Ԫ�صĵ�������
//	//m.emplace_hint(m.begin(), piecewise_construct, forward_as_tuple(23), forward_as_tuple("����"));
//
//	//for (auto& val : m)
//	//	cout << val.first << "," << val.second << "  ";
//	//cout << endl;
//}