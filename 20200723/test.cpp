#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//宏：是在预处理阶段发生替换---代码还没有编译---编译器直接替换，不会进行类型检测---安全性不高
//const修饰：是在编译阶段进行替换---会进行参数类型检测---安全性高

/*
宏常量：为了实现简单，会定义一些宏常量
#define MAX_SIZE 100 在程序中所有用到100的位置都可以使用MAX_SIZE
*/
//#define PI 3.14
//const double pi = 3.14;
//void TestFunc()
//{
//	int r = 2;
//	double s = pi*r*r;
//
//	cout << s << endl;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}

//int main()
//{
//	//要验证被const修饰的a是否为常量，借助定义数组来测试
//	//因为：定义数组时必须要给出数组的大小，而数组的大小必须是常量
//	//编译成功，因为a被const修饰，a是一个常量
//	const int a = 10;
//	int array[a] = { 0 };
//	//编译失败，因为b是一个变量，而定义数组时，需要一个常量来指定数组的大小
//	int b = 10;
//	int array2[b] = { 0 };
//	return 0;
//}
// 在C语言中，被const修饰的变量不能将其称为常量，仍旧是一个变量，只不过该变量不能被修改

//宏的优缺点
/*
宏常量
  优点：一改全改，降低出错概率、提高代码可读性
  缺点：在预处理阶段进行替换，不会进行类型检测，代码的安全性较低
  在C++中，建议尽量使用const修饰的常量替换宏常量
宏函数
  优点：
  1. 不是函数，少了函数调用的开销，可以提高程序的运行效率
  2. 少写一些代码：因为宏函数可以封装多条语句---注意：不是提高了代码的复用率，因为宏函数在预处理阶段展开了
  缺陷：
  1. 宏函数在预处理阶段被替换，不会进行类型检测，代码的可读性比较低
  2. 不能调试
  3. 容易出错，在写的时候每个部分都要加括号
  4. 每个使用宏函数的位置都会被展开，会造成代码膨胀
  5. 宏函数可能会有副作用

  在C++中，对于宏函数建议尽量使用内联函数进行代替
  优点：
  1. 因为是函数，参数有类型，因此在编译阶段会进行参数类型检测，代码安全性高
  2. 在Debug模式下默认不会展开，可以进行调试---也可以通过对编译器设置来验证到底是否展开
  3. 写时候期间不用向宏函数导出加括号，实现简单
  4. 不会有副作用
  5. 在编译阶段已经展开了，少了函数调用的开销，可以提高程序的运行效率


  缺陷：每个使用内联函数的位置几乎都会被展开，会造成代码膨胀
*/

//#define MUL(a,b)((a)*(b))
//int Mul(int left, int right)
//{
//	return left*right;
//}
//
//#define MAX(a,b)(((a)>(b))?(a):(b))
//int main()
//{
//	cout << MUL(2, 3) << endl;
//	cout << Mul(2, 3) << endl;
//
//	int x = 10;
//	int y = 20;
//	int z = MAX(++y, x);
//	cout << z << endl;//MAX求的较大值是22，而不是21，MAX宏产生了副作用
//	return 0;
//}

// 在C++中，被inline关键字修饰的函数称为内联函数
// 内联函数特性：在编译期，编译器会对内联函数进行展开，少了函数调用的开销，可以提高程序的运行效率
//inline int Add(int left, int right)
//{
//	return left + right;
//}
//
//inline int Max(int left, int right)
//{
//	return left > right ? left : right;
//}

/*
release模式下，main函数相当于称为了以下的代码
int main()
{
   return 0;
}
*/

// C语言中有auto的关键字
// auto关键字专门用来修饰函数中定义的变量，表明：该变量为自动存储类型的变量，即该变量会被自动销毁掉

// 因此C++11中，废除了auto在C语言中的作用，给全新的含义:
//   auto不再是一个存储类型指示符，而是作为一个新的类型
//   指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导变量的类型
//int Add(int left, int right)
//{
//	return left + right;
//}
//int main()
//{
//	auto a = 10;
//	auto b = "1234";
//	auto c = 12.34;
//
//	// 注意：auto不是类型
//	// auto此时只是一个占位符
//	// 在编译器编译时，编译器推演d的初始化表达式a+10的类型为int，最终用int替换d之前的auto
//	auto d = a + 10; // 编译器编译完成后  auto d = a + 10;--->int d = a+10;
//	auto ret = Add(10, 20);
//	cout << typeid(ret).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}

//void TestAuto1()
//{
//	auto a = 10;
//	// 使用auto定义指针类型变量时，加不加*都无所谓
//	auto pa = &a;//auto-->替换为int* 
//	auto *pb = &a;//auto-->替换为int
//	cout << typeid(pa).name() << endl;
//	cout << typeid(pb).name() << endl;
//
//	// 注意：auto定义引用类型变量时，auto之后必须要&
//	auto& ra = a;// 让ra引用a
//	auto rra = a; // 注意：rra并不是a的引用，只是定义了一个rra的变量，该变量使用a来进行初始化
//
//	cout << &a << endl;
//	cout << &ra << endl;
//	cout << &rra << endl;
//}
//
//void TestAuto2()
//{
//	// 使用auto在一行定义多个变量时，每个变量的初始化表达式的类型必须一致
//	auto a = 1, b = 2, c = a + b;
//}
//
//// 注意：auto不能用来声明函数的参数
//// 因为函数的参数在定义没有初始化，既然没有初始化，编译器也无法推演形参的实际类型
//// 在用auto定义形参时，给了缺省值之后为什么也不行？
//// 原因：因为不是所有函数的参数都有默认值
//void TestAutoParam(auto a = 10)
//{
//	a++;
//}
//
//void TestAutoArray()
//{
//	int array0[10];
//	int array1[] = { 1, 2, 3 };// array1是一个整形的数组，里面包含3个元素
//	int array2[10] = { 1, 2, 3 };// array2是一个整形的数组，里面包含10个元素，前三个元素为1 2 3，其余元素为0
//	// 注意：auto不能用来定义数组
//	auto array4[] = { 1, 2, 3 };
//}
//int main()
//{
//	TestAuto1();
//	return 0;
//}

//int main()
//{
//	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		cout << array[i] << " ";
//	cout << endl;
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		cout << *p << " ";
//	cout << endl;
//	return 0;
//}

// 因为数组名作为函数的参数时，实际已经退还成一个指针了
//void TestFor(int array[])//void TestFor(int* array)
//{
//	for (auto e : array)
//		cout << e << " ";
//	cout << endl;
//}

// 范围for循环 + 配合auto
int main()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// 打印数组--e:实际就是array数组中每个元素的一份拷贝
	//e改变，数组中的元素不会变
	for (auto e : array)
		cout << e << " ";
	cout << endl;

	// 对数组中每个元素乘2的操作
	// e就是数组中每个元素的别名--->修改e就是修改数组中每个元素
	for (auto& e : array)
		e *= 2;
	for (auto& e : array)
		cout << e << " ";
	cout << endl;
	return 0;
}