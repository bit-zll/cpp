#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 拷贝构造函数：
//	//   特殊的构造函数，一定是单参的，参数必须是类类型对象的引用(一般情况下会在参数前const)
//	//   在使用已经存在的对象创建新对象时，由编译器自动进行调用
//	// 注意：如果用户没有显式实现，则编译器生成一份，并且会完成拷贝的工作
//
//	// 一般拷贝不需要通过形参d改变外部的实参，最好用const对d进行修改
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void PrintDate()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 8, 7);
//	d1.PrintDate();
//
//	// 需求：d2对象在创建好之后与d1对象中的数据一样
//	//Date d2(2020,8,7);
//
//	// 用已经存在的d1来创建一个新对象d2
//	// d2是新创建的对象，既然新创建了对象，肯定要调用构造函数
//	//Date d2 = d1;
//
//	// 因为是用已经存在的d1在创建新对象d2---->拷贝构造函数(复制构造函数)
//	Date d2(d1);
//	d2.PrintDate();
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 8, 7);
//	Date d2(d1);
//	//但是d2对象创建成功后，发现d2对象中的内容与d1对象中的内容完全相同
//	// 用已经存在对象d1拷贝构造新对象d2--->调用的就是编译器生成的默认的拷贝构造函数
//	// 编译器给Date类生成的默认的拷贝构造函数已经能够完成拷贝的构造
//	// 编译器生成默认拷贝构造函数：值的拷贝(内存的拷贝)：将一个对象中的内容原封不动的拷贝到另一个新对象中
//
//	// 对于Date类而言：使用编译器生成的默认拷贝构造函数没有任何问题
//	// Date的拷贝构造函数写不写都可以，如果写了就使用用户所提供的拷贝构造函数，如果没有提供，就使用编译器生成的默认的拷贝构造函数
//	return 0;
//}

// 发现：Date类拷贝构造是否提供没有任何影响
// 问题：是否任何类的拷贝构造函数都可以不用提供，因为编译器会生成一个默认的拷贝构造函数
#include <malloc.h>
#include <string.h>

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			free(_str);
//		}
//	}
//private:
//	char* _str;
//};
//void TestString()
//{
//	String s1("hello");
//	//失败
//	// 用s1拷贝构造s2，肯定要调用拷贝构造函数
//	// 因为String类没有显式提供拷贝构造函数，则使用的是编译器生成的默认的拷贝构造函数
//	// 而默认的拷贝构造函数是按照值的方式进行拷贝，即：将s1对象中的内容原封不动的拷贝到新对象中
//	//浅拷贝
//	//s1和s2在底层共用一段堆空间，s2在销毁时会调用析构函数将空间释放掉，而s1不知道，再次释放而导致程序崩溃
//	String s2(s1);
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	// isLess是日期类的成员函数
//	// 成员函数必须要通过对象来进行调用
//	// 需要一个日期类型的参数
//	// 注意：isLess函数参数也可以是值的方式，只不过按照值的方式传参，在传参时要创建一个临时对象，会影响程序的运行效率
//	//      因此使用引用的方式传参---引用就是实参的别名，不需要拷贝一个临时对象，传参的效率就高
//	// 一般情况下：类类型作为函数的参数时，基本都是按照引用的方式传递的，如果不需要通过形参改变外部的实参，最好加上const来进行限制
//	bool isLess(const Date& d)
//	{
//		if ((_year < d._year) ||
//			(_year == d._year&&_month < d._month) ||
//			(_year == d._year&&_month == d._month&&_day < d._day))
//		{
//			return true;
//		}
//		return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2020, 8, 7);
//	Date d2(2020, 8, 8);
//	if (d1.isLess(d2))
//	{
//		cout << "d1<d2" << endl;
//	}
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// <的运算符的重载
//	bool operator<(const Date& d)
//	{
//		if ((_year < d._year) ||
//			(_year == d._year&&_month < d._month) ||
//			(_year == d._year&&_month == d._month&&_day < d._day))
//		{
//			return true;
//		}
//		return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 8, 7);
//	Date d2(2020, 8, 8);
//	if (d1 < d2)
//	{
//		cout << "d1<d2" << endl;
//	}
//	return 0;
//}

//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year&&
//			_month == d._month&&
//			_day == d._day;
//	}
//	bool operator!=(const Date& d)
//	{
//		return ! (*this == d);
//	}
//};
// 该函数编译失败
// @运算符根本就没有
//void operator@(const Date& d)
//{}

// +：有两个操作数，函数必须要提供两个操作数
// 编译失败，
// +左右两侧如果都是int类型的数据，编译器本来就支持，再重载时候就多此一举
// 而且还形成了无线递归
// 注意：在进行运算符重载时，必须有一个类类型或者枚举类型的参数
//int operator+(int left, int right)
//{
//	return left + right;
//}

//enum DATA{ONE, TWO, TRHEE};
//
//int operator+(DATA op1, int op2)
//{
//	return op1 - op2;
//}
//int main()
//{
//	Date d1(2020, 8, 7);
//	Date d2(d1);
//	if (d1 != d2)
//	{
//		cout << "d1!=d2" << endl;
//	}
//	else
//	{
//		cout << "d1==d2" << endl;
//	}
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void PrintDate()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 8, 7);
//	Date d2(2020, 8, 8);
//	// 注意： d2 = d1；应该调用赋值运算符重载，但是Date类中没有提供赋值运算符重载
//	// 代码通过编译
//	// 因为：赋值运算符重载--->用户没有显式实现时，编译器会自动生成一个
//	// 对于Date类使用编译器生成的默认的赋值运算符重载没有任何问题
//	d2 = d1;
//	d1.PrintDate();
//	d2.PrintDate();
//	return 0;
//}

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	/*~String()
	{
		if (_str)
		{
			free(_str);
		}
	}*/
private:
	char* _str;
};
void TestString()
{
	String s1("hello");
	String s2("world");

	s2 = s1;
}
int main()
{
	TestString();
	return 0;
}