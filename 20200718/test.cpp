#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//N1��һ�������ռ�
//a��Add��N1�����ռ��еĳ�Ա
//�����ռ䣺ʵ�ʾ���һ���������ֵ�������
//�����ʽ1
//namespace N1
//{
//	int a = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//
//int a = 20;
//
//int main()
//{
//	int a = 30;
//	//�ж��ͬ����a���ڲ�ͬ���������ں�����ֱ�ӷ��ʣ��ǰ��վͽ�ԭ��
//	printf("%d\n", a);//���ʵ��Ǻ������е�a
//	printf("%d\n", ::a);//����ȫ���������е�a-->::�����������
//	printf("%d\n", N1::a);
//
//	printf("%d\n", N1::Add(10, 20));
//	return 0;
//}
//�����ռ䶨���ʽ2--�����ռ����Ƕ��
//namespace N2
//{
//	int a = 40;
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//	namespace N3
//	{
//		int a = 50;
//		int Mul(int left, int right)
//		{
//			return left*right;
//		}
//	}
//}

//int main()
//{
//	printf("%d\n", N2::a);
//	printf("%d\n", N2::N3::a);
//	return 0;
//}

//�����ʽ3--���������ռ��������ͬ
//��C++�У�һ�������п��Գ�����ͬ���ֵ������ռ�
//���������ս���ͬ���������ռ�ϲ���һ��
//namespace N
//{
//	int a = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//namespace N
//{
//	int b = 20;
//	int Sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", N::b);
//	return 0;
//}
//�����ռ��ʹ�÷�ʽ��
//1.ֱ���ڳ�Աǰ��N::
//2.using N:;a;ע�⣺��ǰ�ļ���ȫ���������в�����a���еĻ��ͳ�ͻ��
//3.using namespace N
//namespace N
//{
//	int a = 10;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//using N::a;
//using namespace N;
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", a);
//	Add(10, 20);
//	return 0;
//}

#include <iostream>
using namespace std;
//int main()
//{
//	cout << 10 << endl;
//	cout << 12.34 << endl;
//	cout << "abcdef" << endl;
//	cout << 888 << " " << "!!!" << endl;
//	return 0;
//}

//int main()
//{
//	int a, b;
//	float c;
//	char d;
//
//	cin >> a;
//	cout << a << endl;
//
//	cin >> a >> b;
//	cout << a << " " << b << endl;
//
//	cin >> a >> c >> d;
//	cout << a << " " << c << " " << d << endl;
//	return 0;
//}

//C++���������ں������������Լ�����ֵ���ͼ������ϸ�
void test1()
{
	//printf("test1()\n");
	cout << "test1()" << endl;
}
void test2(int a)
{
	//printf("test2():%d\n", a);
	cout << "test2():" << a << endl;
}
int main()
{
	test1();
	test2(10);
	return 0;
}