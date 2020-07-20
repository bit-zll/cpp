#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//缺省参数：在声明或定义函数时，给函数的参数带上默认值，在函数调用时，如果传递了实参
//就用实参，没有传递实参则使用默认值

//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(100);
//	TestFunc();
//	return 0;
//}

//缺省参数的分类
//1.全缺省参数：所有参数都带有默认值
//2.半缺省参数：部分参数带有默认值

//全缺省参数
//void TestFunc1(int a = 1, int b = 2, int c = 3)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//半缺省参数
//void TestFunc2(int a, int b = 2, int c = 3)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//int main()
//{
//	TestFunc1();
//	TestFunc1(10);
//	TestFunc1(10, 20);
//	TestFunc1(10, 20, 30);
//
//	TestFunc2(10);
//	TestFunc2(10, 20);
//	TestFunc2(10, 20, 30);
//	return 0;
//}

//缺省参数：不能在声明和定义时候同时给出
//因为两个位置同时给，万一给的默认值不一致，到底使用哪一个
//在函数声明时给出好
//函数声明
//int g_a = 100;
//void TestFunc(int a = g_a);
//函数定义
//void TestFunc(int a)
//{
//	cout << a << endl;
//}

//定义一个通用类型的加法函数--任意数据类型都要能够处理
//C语言中;函数名字一定不能相同的，如果相同编译时报错：函数重定义
//int AddII(int left, int right)
//{
//	return left + right;
//}
//double AddDD(double left, double right)
//{
//	return left + right;
//}
//char AddCC(char left, char right)
//{
//	return left + right;
//}
//int main()
//{
//	AddII(10, 20);
//	AddDD(10.0, 20.0);
//	AddCC('1','2');
//	return 0;
//}

//C++
//函数重载：多个函数作用域相同，函数名字必须相同，参数列表必须不同（参数个数、参数类型、类型次序）
//与返回值类型是否相同无关（如果两个函数仅仅只是因为返回值类型不同是不能构造重载）
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//char Add(char left, char right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add('1', '2');
//	return 0;
//}

// 参数列表必须要不同: 参数个数不同  参数类型不同  类型次序不同
//void TestFunc()
//{}
//void TestFunc(int a)
//{}
//void TestFunc(double a)
//{}
//void TestFunc(int a, double)
//{}
//void TestFunc(double a, int b)
//{}

//仅仅返回值类型不同就不能构成重载
//该位置的函数调用就不知道调用带有返回值的还是没有返回值的TestFunc函数--会产生二义性
//int TestFunc(double a, int b)
//{}

// 函数重载调用原理
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//double Add(int left, double right)
//{
//	return left + right;
//}
//
///*
//在编译器编译阶段，会对传递实参的类型进行推演，然后根据推演的结果选择对应类型的函数进行调用
//注意：
//推演完成后，如果有合适的类型重载的函数则调用
//否则会发生隐式类型转化---转化之后有合适类型则调用，否则则报错
//*/
//int main()
//{
//	Add(1, 2);      // int, int--->int类型的加法
//	Add(1.0, 2.0);  // double, double--->double类型的加法函数
//
//	// char,char--->找Add(char,char)函数，遗憾该函数没有，
//	// 发现Add(int,int)函数，而char和int之间可以发生隐式类型转化
//	Add('1', '2');
//
//	/*
//	double和int之间可以相互转换
//	int,double---->Add(int,double), 没有该函数
//
//	此时会发生隐式类型转化
//	int,double--->Add(int,int)
//	int,double--->Add(double, double)
//
//	编译器生气了--->报错
//	*/
//	 //Add(1, 2.0);
//	// 解决方式一：用户自己进行强转
//	Add(1, (int)2.0);  // --->Add(int,int)
//
//	// 解决方式二：用户给出对应的函数重载
//	Add(1, 2.0);
//
//	// Add("hello", "world");  // char*  char* 没有合适的转换供调用，编译时报错
//	return 0;
//}

// 函数重载：C语言不支持、C++支持----为什么C语言不支持函数重载呢？C++是如何支持函数重载？

// 为什么C语言不支持函数重载呢？--->因为：C语言编译器对函数名字修饰规则非常简单，仅仅只是在函数名之前增加了_
//int Add(int left, int right);   // C语言编译器最终将该函数名字修改:_Add
//{
//	return left + right;
//}

//double Add(double left, double right);  // C语言编译器最终将该函数名字修改:_Add
//{
//	return left + right;
//}

/*
C/C++程序从编辑完到可以运行：
预处理：头文件展开、宏替换...
编译：编译器会按照该中语言的语法规则检测代码是否存在语法问题
汇编：翻译过程--->将汇编指令翻译成对应的二进制格式指令  mov:1010  push:1011   obj文件
链接: 组装--->将多个目标文件整合成一个文件 + 解决地址问题

可以生成一个可执行程序
*/
//int main()
//{
//	/*
//	push 14h
//	push 0Ah
//	call 函数的入口地址_Add
//	*/
//	//Add(10, 20);    // error LNK2019: 无法解析的外部符号 _Add，该符号在函数 _main 中被引用
//	Add(1.0, 2.0);    // error LNK2019: 无法解析的外部符号 _Add，该符号在函数 _main 中被引用
//	return 0;
//}

//int Add(int left, int right)   // C++编译器最终将该函数名字修改:?Add@@YAHHH@Z
//{
//	return left + right;
//}

//double Add(double left, double right)  // C++编译器最终将该函数名字修改:?Add@@YANNN@Z
//{
//	return left + right;
//}

double Add(int left, double right);

/*
C++编译器对函数名字的修饰规则：
vs
?Add@@YAHHH@Z---->H:int
?Add@@YANNN@Z---->N:double
?Add@@YANHN@Z
?开头 之后就是函数的名字Add  第一个@符号表示函数名字结束  @YA之后跟函数返回值以及参数类型  @Z表示参数列表结束

C++编译器在对函数名字修饰时：最终将参数类型信息编译到名字中去了
*/
int main()
{
	//Add(1, 2);   // 无法解析的外部符号 "int __cdecl Add(int,int)" (?Add@@YAHHH@Z)
	//Add(1.0, 2.0); // 无法解析的外部符号 "double __cdecl Add(double,double)" (?Add@@YANNN@Z)
	Add(1, 2.0);   // 无法解析的外部符号 "double __cdecl Add(int,double)" (?Add@@YANHN@Z)
	return 0;
}