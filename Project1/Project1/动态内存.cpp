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
//	//��� p[i][j][k] ��ά����
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
//	//����ڴ�
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
//	cout <<"6�����ǣ�" <<6 * 30+3<<"��"<<'\n'<<"����14Ϊ��"<<(6*30+3)/14.0<<'\n'<<"����ʱ��Ϊ��" <<365/2.0 <<endl;
//
//	return 0;
//}
//
