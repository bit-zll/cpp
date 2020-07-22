#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//void test(int a)
//{}
//void test(int& a)
//{}
//int main()
//{
//	//test(10);
//	int r = 10;
//	test(r);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << typeid(a).name() << endl;
//	cout << typeid(ra).name() << endl;
//	return 0;
//}

//#include <ctime>
//struct A
//{
//	int array[100000];
//};
//void TestValue(A a)
//{}
//void TestRef(A& a)
//{}
//void TestPtr(A* a)
//{}
//void TestFunc()
//{
//	A a;
//	//传值，在传参期间需要进行实参的一份拷贝
//	size_t begin1 = clock();
//	for (int i = 0; i < 10000; i++)
//		TestValue(a);
//	size_t end1 = clock();
//	//引用是别名，在传参期间不需要进行拷贝
//	size_t begin2 = clock();
//	for (int i = 0; i < 10000; i++)
//		TestRef(a);
//	size_t end2 = clock();
//	//传址，在传参期间不需要进行对象的拷贝
//	size_t begin3 = clock();
//	for (int i = 0; i < 10000; i++)
//		TestPtr(&a);
//	size_t end3 = clock();
//	cout << "传值性能：" << end1 - begin1 << endl;
//	cout << "传引用性能：" << end2 - begin2 << endl;
//	cout << "传址性能：" << end3 - begin3 << endl;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}

//引用可以达到和指针类似的效果，比如：都可以通过形参来改变外部的实参
//问题：指针和引用有什么区别

//在底层实现上：引用就是按照指针方式实现的
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 100;
//
//	int& ra = a;
//	ra = 100;
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(int* left, int* right)
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	Swap(&a, &b);
//	cout << a << " " << b << endl;
//	return 0;
//}

int main()
{
	int a = 10;
	int& ra = a;
	ra++;//注意：在底层处理上，编译器会对ra解引用找到a

	int b = 20;
	int* p = &b;
	p++;//指针只是指向一段连续的空间

	char c = 'a';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;//4 在32位平台下。任何指针都占有4个字节
	cout << sizeof(rc) << endl;//1 引用类型实际就是其引用实体类型的大小

	//有多级指针
	int* p1 = NULL;
	int** p2 = NULL;
	int*** p3 = NULL;

	//没有多级引用--->没有这个名词
	return 0;
}