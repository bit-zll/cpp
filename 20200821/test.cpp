#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class Date
//{
//public:
//	//1.无参构造函数
//	Date()
//	{}
//
//	//2.带参构造函数
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
//void TestDate()
//{
//	Date d1;//调用无参构造函数
//	Date d2(2020, 8, 21);//调用带参的构造函数
//}

//class Date
//{
//public:
//	//无参构造函数
//	Date()
//	{
//		_year = 2020;
//		_month = 8;
//		_day = 21;
//	}
//	//全缺省构造函数
//	Date(int year = 2020, int month = 8, int day = 21)
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
//void Test()
//{
//	//不能通过编译，因为默认构造函数只能有一个
//	Date d1;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	//基本类型（内置类型）
//	int _year;
//	int _month;
//	int _day;
//	//自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

#include <malloc.h>
#include <assert.h>
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity*sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = 0;
//	}
//	~SeqList()
//	{
//		if (_pData)
//		{
//			free(_pData);
//			_pData = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};

#include <string.h>
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2020, int month = 8, int day = 1)
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
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(d1);
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
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2020, 8, 21);
//	Date d2(d1);
//	if (d1 == d2)
//		cout << "d1 == d2" << endl;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year=1900, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date& operator=(const Date& d)
//	{
//		//避免给自己赋值
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
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
//	Date d2(2020, 8, 21);
//	d2 = d1;
//	d2.PrintDate();
//	return 0;
//}

//class Date
//{
//public:
//	void Display()
//	{
//		cout << "Display()" << endl;
//		cout << _year << endl;
//		cout << _month << endl;
//		cout << _day << endl;
//	}
//	void Display()const
//	{
//		cout << "Display()const" << endl;
//		cout << _year << endl;
//		cout << _month << endl;
//		cout << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Display();
//
//	const Date d2;
//	d2.Display();
//	return 0;
//}

//class Date
//{
//public:
//	Date* operator&()
//	{
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	int a[] = { 0, 2, 4, 6, 8, 10 };
//	int *p = a + 1;
//	printf("%d\n", *(--p));
//	return 0;
//}

//int main()
//{
//	int c[] = { 1, 3, 5 };
//	int *k = c + 1;
//	printf("%d\n", *++k);
//	return 0;
//}

//#define MA(X,Y)(X*Y)
//int main()
//{
//	int i = 5;
//	i = MA(i, i + 1) - 7;
//	printf("%d\n", i);
//	return 0;
//}

//#define sum(a,b,c) a+b+c
//int main()
//{
//	int i = 3;
//	int j = 2;
//	printf("%d\n", i*sum(i, (i + j), j));
//	return 0;
//}

//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//int main()
//{
//	printf("%d\n", f(1));
//	return 0;
//}

//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}
//int main()
//{
//	printf("%d\n", (func()));
//	return 0;
//}

#include <stdlib.h>

//void DeleteStr(char* str1, char* str2)
//{
//	char* pFast = str1;
//	char* pSlow = str2;
//	int a[256] = { 0 };
//	int n = strlen(str2);
//	for (int i = 0; i < n; ++i)
//	{
//		a[str2[i]] = 1;
//	}
//	while (*pFast)
//	{
//		if (a[*pFast] == 0)
//		{
//			*pSlow = *pFast;
//			pSlow++;
//		}
//		pFast++;
//	}
//	*pSlow = '\0';
//}
//int main()
//{
//	char str1[256] = "They are students.";
//	char str2[256] = "aeiou";
//	DeleteStr(str1, str2);
//	printf("%s\n", str2);
//	return 0;
//}