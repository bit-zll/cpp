#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void SetDate(int year, int month, int day)
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
//int main()
//{
//	Date d1;
//	d1.SetDate(2020, 8, 1);
//	d1.PrintDate();
//
//	return 0;
//}

//class Date
//{
//public:
//	// 构造函数是一个特殊的成员函数，特殊：
//	// 构造函数的名字必须与类名相同
//	// 构造函数没有返回值类型，即使加void也不行
//	// 构造函数是在创建对象时由编译器自动进行调用，并且在对象的生命周期内只调用一次
//	// 作用：主要是创建对象时完成对当前对象的初始化工作
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
//void TestDate()
//{
//	Date d(2020, 8, 1);
//	d.PrintDate();
//}
//int main()
//{
//	TestDate();
//
//	Date d2(2020, 8, 2);
//	d2.PrintDate();
//	return 0;
//}

//构造函数可以重载
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date()
//	{
//		_year = 2020;
//		_month = 8;
//		_day = 2;
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
//int main()
//{
//	Date d1(2020, 8, 1);
//	d1.PrintDate();
//
//	Date d2;
//	d2.PrintDate();
//	return 0;
//}

// 如果一个类没有显式定义(用户写出)任何构造函数，编译器会生成一个默认的构造函数，
// 注意：编译器生成的构造函数一定是无参的，用户一旦给出构造函数，编译器就不会生成了

// 全缺省的构造函数 和 无参的构造函数统称为 默认的构造函数
// 并且：全缺省的构造函数 和 无参的构造函数不能同时存在
//class Date
//{
//public:
//	// 全缺省的构造函数
//	Date(int year = 2020, int month = 8, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 无参的构造函数
//	/*Date()
//	{
//		_year = 2020;
//		_month = 8;
//		_day = 1;
//	}*/
//	void PrintDate()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.PrintDate();
//
//	Date d2(2020,8,2);
//	d2.PrintDate();
//	return 0;
//}

// 编译器生成的默认构造函数中：
// 将对象中内置类型定义的成员变量初始化为随机值
// 将对象中包含的类型类型对象成员---调用成员对应类的默认构造函数来初始化

//class Time
//{
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//	{
//		_hour = hour;
//		_minute = minute;
//		_second = second;
//	}
//	void PrintTime()
//	{
//		cout << _hour << "/" << _minute << "/" << _second << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	// 在Date类构造函数执行时，先跳转到Time类构造函数位置执行，将日期类中中的_t的对象初始化完整
//	// 然后再执行Date类的构造函数体给_year\_month\_day来进行赋值
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
//	Time _t;
//};
//int main()
//{
//	Date d1(2020,8,1);
//	d1.PrintDate();
//	Time t1;
//	t1.PrintTime();
//	return 0;
//}
//#include <malloc.h>
//
//typedef int DataType;
//class SeqList
//{
//public:
//	// 对象在创建时，给对象中放数据(资源)
//	SeqList(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)*capacity);
//		_capacity = capacity;
//		_size = 0;
//	}
//	// 析构函数
//	// 在对象被销毁时，由编译器自动进行调用，完整对象中资源清理工作
//	// 析构函数一定是无参的，不能带有任何类型的参数
//	// 析构函数不能有返回值
//	// 一个类只能有一个析构函数
//	~SeqList()
//	{
//		if (_array)
//		{
//			free(_array);
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//	void PushBack(DataType data)
//	{
//		_array[_size++] = data;
//	}
//	void PopBack()
//	{
//		if (Empty())
//			return;
//		--_size;
//	}
//	size_t Size()
//	{
//		return _size;
//	}
//	size_t Capacity()
//	{
//		return _capacity;
//	}
//	bool Empty()
//	{
//		return _size == 0;
//	}
//private:
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//};
//void TestSeqList()
//{
//	SeqList s;
//	s.PushBack(1);
//	s.PushBack(2);
//	s.PushBack(3);
//	cout << s.Size() << endl;
//	cout << s.Capacity() << endl;
//}
//int main()
//{
//	TestSeqList();
//	return 0;
//}

#include <malloc.h>
#include <string.h>

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
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};
void TestString()
{
	String s1;
	String s2("zhaoleilei");
}

class Person
{
private:
	String _name;
	int _age;
};
void TestPerson()
{
	Person p;
	// 在构造Person对象p时，从汇编代码中看到，编译器给Person类生成了一个默认的构造函数
	// 而生成的默认构造函数中，主要调用了String类的构造函数，目的就是对p对象中所包含的String类型的name
	// 来进行初始化
	// 注意：在989行不能直接调用call String(), 因为在989行创建的是一个Person类型的对象，就要调用Person
	// 的构造函数，来完成Person对象中所包含的String类型的name的初始化工作，因此编译器给Person类生成一个默认的构造函数


	// 在P对象销毁时，因为p对象中包含有String类型的name，name中管理资源，因此必须要调用String类的析构函数
	// 完成p对象中所包含的String类型的name的资源清理工作
	// 但是在函数退出时，不能直接调用String类的析构函数，因为现在析构的是Person类的对象，直接调用String类的析构函数讲不通
	// 析构那个类的对象，调用那个类的析构函数
	// 因此：编译器给Person类生成了一个默认的析构函数，在默认的析构函数中调用String类的析构函数，完成p对象中所包含的String类型name的资源清理工作
	/*
	编译器给Person类生成的析构函数
	~Person()
	{
	call ~String();  // 清理Person类对象中包含的String类型成员name中的资源
	}
	*/
}
int main()
{
	TestString();
	TestPerson();
	return 0;
}