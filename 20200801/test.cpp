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
//	// ���캯����һ������ĳ�Ա���������⣺
//	// ���캯�������ֱ�����������ͬ
//	// ���캯��û�з���ֵ���ͣ���ʹ��voidҲ����
//	// ���캯�����ڴ�������ʱ�ɱ������Զ����е��ã������ڶ��������������ֻ����һ��
//	// ���ã���Ҫ�Ǵ�������ʱ��ɶԵ�ǰ����ĳ�ʼ������
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

//���캯����������
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

// ���һ����û����ʽ����(�û�д��)�κι��캯����������������һ��Ĭ�ϵĹ��캯����
// ע�⣺���������ɵĹ��캯��һ�����޲εģ��û�һ���������캯�����������Ͳ���������

// ȫȱʡ�Ĺ��캯�� �� �޲εĹ��캯��ͳ��Ϊ Ĭ�ϵĹ��캯��
// ���ң�ȫȱʡ�Ĺ��캯�� �� �޲εĹ��캯������ͬʱ����
//class Date
//{
//public:
//	// ȫȱʡ�Ĺ��캯��
//	Date(int year = 2020, int month = 8, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// �޲εĹ��캯��
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

// ���������ɵ�Ĭ�Ϲ��캯���У�
// ���������������Ͷ���ĳ�Ա������ʼ��Ϊ���ֵ
// �������а������������Ͷ����Ա---���ó�Ա��Ӧ���Ĭ�Ϲ��캯������ʼ��

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
//	// ��Date�๹�캯��ִ��ʱ������ת��Time�๹�캯��λ��ִ�У������������е�_t�Ķ����ʼ������
//	// Ȼ����ִ��Date��Ĺ��캯�����_year\_month\_day�����и�ֵ
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
//	// �����ڴ���ʱ���������з�����(��Դ)
//	SeqList(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(sizeof(DataType)*capacity);
//		_capacity = capacity;
//		_size = 0;
//	}
//	// ��������
//	// �ڶ�������ʱ���ɱ������Զ����е��ã�������������Դ������
//	// ��������һ�����޲εģ����ܴ����κ����͵Ĳ���
//	// �������������з���ֵ
//	// һ����ֻ����һ����������
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
	// �ڹ���Person����pʱ���ӻ������п�������������Person��������һ��Ĭ�ϵĹ��캯��
	// �����ɵ�Ĭ�Ϲ��캯���У���Ҫ������String��Ĺ��캯����Ŀ�ľ��Ƕ�p��������������String���͵�name
	// �����г�ʼ��
	// ע�⣺��989�в���ֱ�ӵ���call String(), ��Ϊ��989�д�������һ��Person���͵Ķ��󣬾�Ҫ����Person
	// �Ĺ��캯���������Person��������������String���͵�name�ĳ�ʼ����������˱�������Person������һ��Ĭ�ϵĹ��캯��


	// ��P��������ʱ����Ϊp�����а�����String���͵�name��name�й�����Դ����˱���Ҫ����String�����������
	// ���p��������������String���͵�name����Դ������
	// �����ں����˳�ʱ������ֱ�ӵ���String���������������Ϊ������������Person��Ķ���ֱ�ӵ���String���������������ͨ
	// �����Ǹ���Ķ��󣬵����Ǹ������������
	// ��ˣ���������Person��������һ��Ĭ�ϵ�������������Ĭ�ϵ����������е���String����������������p��������������String����name����Դ������
	/*
	��������Person�����ɵ���������
	~Person()
	{
	call ~String();  // ����Person������а�����String���ͳ�Աname�е���Դ
	}
	*/
}
int main()
{
	TestString();
	TestPerson();
	return 0;
}