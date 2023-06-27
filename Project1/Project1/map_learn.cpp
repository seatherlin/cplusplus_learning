//#include <iostream>
//#include<string>
//#include <map>
//using  namespace std;
//
//class CGirl        // 超女类。
//{
//public:
//	string m_name;   // 超女姓名。
//	int      m_age;       // 超女年龄。
//
//	/*CGirl() : m_age(0) {
//		cout << "默认构造函数。\n";
//	}*/
//	CGirl(const string name, const int age) : m_name(name), m_age(age) {
//		cout << "两个参数的构造函数。\n";
//	}
//	CGirl(const CGirl & g) : m_name(g.m_name), m_age(g.m_age) {
//		cout << "拷贝构造函数。\n";
//	}
//};
//
//int main()
//{
//	//map<int, CGirl> mm;
//	//mm.insert     (pair<int, CGirl>(8, CGirl("冰冰", 18)));                // 一次构造函数，两次拷贝构造函数。
//	//mm.insert     (make_pair<int, CGirl>(8, CGirl("冰冰", 18)));     // 一次构造函数，两次拷贝构造函数。
//	//mm.emplace(pair<int, CGirl>(8, CGirl("冰冰", 18)));                // 一次构造函数，两次拷贝构造函数。
//	//mm.emplace(make_pair<int, CGirl>(8, CGirl("冰冰", 18)));     // 一次构造函数，两次拷贝构造函数。
//	//mm.emplace(8, CGirl("冰冰", 18));                                             // 一次构造函数，一次拷贝构造函数。
//	//mm.emplace(8, "冰冰", 18);                                                        // 错误。
//	//mm.emplace(piecewise_construct, forward_as_tuple(8), forward_as_tuple("冰冰", 18));  // 一次构造函数。
//
//	//for (const auto& val : mm)
//	//	cout << val.first << "," << val.second.m_name << "," << val.second.m_name << "  ";
//	//cout << endl;
//
//	//return 0;
//
//	map<int, string> m;
//
//	// 1）void insert(initializer_list<pair<K,V>> il);  // 用统一初始化列表在容器中插入多个元素。
//	m.insert({ { 8,"冰冰" }, { 3,"西施" } });
//	m.insert({ pair<int,string>(1,"幂幂"), make_pair<int,string>(7,"金莲"), {5,"西瓜"} });
//	m.insert({ { 18,"冰冰" }, { 3,"西施" } });
//
//	// 2）pair<iterator,bool> insert(const pair<K,V> &value);  
//	// 在容器中插入一个元素，返回值pair：first是已插入元素的迭代器，second是插入结果。
//	auto ret = m.insert(pair<int, string>(31, "花花"));
//	if (ret.second == true) cout << "插入成功：" << ret.first->first << "," << ret.first->second << endl;
//	else cout << "插入失败。\n";
//
//	// 3）void insert(iterator first, iterator last);  // 用迭代器插入一个区间的元素。
//
//	// 4）pair<iterator, bool> emplace(...);  
//	// 将创建新键值对所需的数据作为参数直接传入，map容器将直接构造元素。
//	// 返回值pair：first是已插入元素的迭代器，second是插入结果。
//	//auto ret1 = m.emplace(20, "花花");
//	//if (ret1.second == true) cout << "插入成功：" << ret1.first->first << "," << ret1.first->second << endl;
//	//else cout << "插入失败。\n";
//
//	//// 5）iterator emplace_hint(const_iterator pos, ...); 
//	//// 功能与第4）个函数相同，第一个参数提示插入位置，该参数只有参考意义，如果提示的位置是正确的，
//	//// 对性能有提升，如果提示的位置不正确，性能反而略有下降，但是，插入是否成功与该参数元关。
//	//// 该参数常用end()和begin()。成功返回新插入元素的迭代器；如果元素已经存在，则插入失败，返回现
//	//// 有元素的迭代器。
//	//m.emplace_hint(m.begin(), piecewise_construct, forward_as_tuple(23), forward_as_tuple("冰棒"));
//
//	//for (auto& val : m)
//	//	cout << val.first << "," << val.second << "  ";
//	//cout << endl;
//}