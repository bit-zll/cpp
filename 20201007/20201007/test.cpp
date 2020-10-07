#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class Test
//{
//public:
//	Test(int t)
//		: _t(t)
//	{}
//	Test& operator=(const Test& t)
//	{
//		if (this != &t)
//		{
//			_t = t._t;
//		}
//		return *this;
//	}
//	int _t;
//};
//
////赋值运算符重载必须写成类的成员函数
////Test& operator= (Test& t)
////{
////    return t;
////}
////注意：不是说所有的运算符重载都要写成类的成员函数
////比如：重载的输出运算符
//
//int main()
//{
//	Test t1(10);
//	Test t2(20);
//
//	t1 = t2;
//	return 0;
//}

class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " "<< _t <<endl;
	}
	~Test()
	{
		cout << "~Test():" << this <<" " << _t << endl;
	}
	int _t;
};
Test t1(10);

int main()
{
	Test t2(20);
	Test t3(30);
	static Test t4(40);

	return 0;
}

//1.全局对象随程序的启动而创建，随程序的结束而被销毁
//2.静态局部对象，函数第一次被调用时创建，后续每次调用则不会再来创建，随程序的结束而被销毁
//3.函数体中局部对象：伴随函数的运行而创建，随着函数的结束而销毁。
//局部对象存储在栈上，栈上的对象创建和销毁的规则符合栈的特性，即先创建的后销毁。