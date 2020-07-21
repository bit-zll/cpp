#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//全缺省的函数与同名的无参函数只能存在一个
//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc()
//{
//	cout << "void TestFunc()" << endl;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}

//void Swap(int left, int right)
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
//	cout << a << " " << b << endl;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	Swap(&a, &b);
//	cout << a << " " << b << endl;
//	return 0;
//}
//传值和传址有什么区别？有什么优缺点？
//1.传值：形参将来接受到的是实参的一份临时拷贝，
//        在函数中如果对形参进行改变，不会影响外部实参
//2.传址：形参将来放置的是实参的地址，通过对形参解引用拿到实参，
//        对形参解引用进行修改，实际修改的是外部的实参，可以通过形参来改变外部的实参
//3.传址比传值是效率高：传值需要的是实参本身的一份临时拷贝，如果实参类型比较大
//将来拷贝的副本就比较大。传址需要的是实参地址的一份拷贝，形参只占4个字节（32位）
//传址不仅效率高，而且节省空间
//4.传值比传址更安全--指针必须要判空
//5.传值比传址代码的可读性高

//有什么优缺点？
//传值：
//优点：1.代码可读性高、较安全2.不想通过形参改变外部的实参，及时将形参改了也不会影响外部实参
//缺点：1.传参效率低，浪费空间（传递的是实参的副本）2.如果想要通过形参改变外部实参时，做不到
//传地址：
//优点：1.传参效率高，节省空间（传递的是实参的地址--32位平台4字节）2.可以通过形参改变外部的实参
//缺点：1.安全性低，可读性低2.如果不想通过形参改变外部实参时可能会产生副作用

//void TestRef()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	cout << a << endl;
//	cout << &a << " " << &ra << endl;
//}
//int main()
//{
//	TestRef();
//	return 0;
//}
//引用：可以达到指针类似的效果
//如果需要一级指针，可以直接用引用来代替
//如果需要二级指针，可以直接使用一级指针的引用来代替
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int& rb = a;
//	int& rc = a;
//	cout << &a << " " << &ra << " " << &rb << " " << &rc << endl;
//	return 0;
//}

//问题：引用变量的声明周期长还是实体的生命周期长？实体

//常引用-->const类型的引用
//int main()
//{
//	const int a = 10;//a不能被修改
//	//int& ra = a;
//	const int& ra = a;
//	cout << &a << " " << &ra << endl;
//
//	const int& rb = 100;
//
//	double d = 12.34;
//	const int& rd = d;
//	d = 23.34;
//	cout << rd << endl;//rd不会改变，因为rd的地址和d的地址不同
//	return 0;
//}

//引用的应用场景
//1.概念：直接给某个实体取别名---为了写代码简单
//2.作为函数的形参，可以达到指针类似的效果---即可以通过形参改变外部的实参
//3.用引用作为函数的返回值
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}
int main()
{
	int& sum = Add(1, 2);
	cout << sum << endl;
    Add(3, 4);//sum也变为7
	return 0;
}