//# include<iostream>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//
//	int ***p;
//	const int len = 5, row = 6, col = 7;
//	p = new int **[len];
//	for (int i = 0; i < len; i++)
//	{
//		p[i] = new int *[row];
//		for (int j = 0; j < row; j++)
//		{
//			p[i][j] = new int[col];
//		}
//	}
//
//
//	//输出 p[i][j][k] 三维数据
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			for (int k = 0; k < col; k++)
//			{
//				p[i][j][k] = i + j + k;
//				cout << p[i][j][k] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//
//
//	ofstream outfile;
//	outfile.open("read.dat");
//
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			for (int k = 0; k < col; k++)
//			{
//				outfile << p[i][j][k]<<' ';
//			}
//			outfile << endl;
//		}
//		outfile << endl ;
//	}
//	outfile.close();
//
//
//
//	//清空内存
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < row; j++)
//		{
//			delete[] p[i][j];
//		}
//	}
//	for (int i = 0; i < len; i++)
//	{
//		delete[]p[i];
//	}
//
//	delete[]p;
//
//	cout <<"6个月是：" <<6 * 30+3<<"天"<<'\n'<<"除于14为："<<(6*30+3)/14.0<<'\n'<<"半年时间为：" <<365/2.0 <<endl;
//
//	return 0;
//}
//
