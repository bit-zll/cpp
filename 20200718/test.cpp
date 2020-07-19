#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//N1是一个命名空间
//a和Add是N1命名空间中的成员
//命名空间：实际就是一个带有名字的作用域
//定义格式1
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
//	//有多个同名的a处在不同的作用域，在函数中直接访问，是按照就近原则
//	printf("%d\n", a);//访问的是函数体中的a
//	printf("%d\n", ::a);//访问全局作用域中的a-->::作用域运算符
//	printf("%d\n", N1::a);
//
//	printf("%d\n", N1::Add(10, 20));
//	return 0;
//}
//命名空间定义格式2--命名空间可以嵌套
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

//定义格式3--两个命名空间的名字相同
//在C++中，一个工程中可以出现相同名字的命名空间
//编译器最终将相同名称命名空间合并成一个
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
//命名空间的使用方式：
//1.直接在成员前加N::
//2.using N:;a;注意：当前文件的全局作用域中不能有a，有的话就冲突了
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

//C++编译器对于函数参数类型以及返回值类型检测更加严格
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