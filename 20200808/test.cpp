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
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(const Date& d):" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// ��ֵ�ķ�ʽ���������Ͷ����ڴ����ڼ����������ÿ������캯������һ����ʱ�Ķ���
//// ȱ�ݣ����������Ч�ʵ�
//void TestDate1(Date dd)
//{}
//
//// һ������º���ʹ����ֵ�ķ�ʽ���������͵Ĳ�����һ�㶼��ʹ�����õķ�ʽ��Ϊ��������
//// �ŵ㣺����Ч�ʷǳ���(����һ�ο����������)
//// ȱ�ݣ�����޸��βξͻ��޸��ⲿʵ��
//void TestDate2(Date& dd)
//{}
//
//void TestDate3(const Date& dd)
//{}
//
//Date TestDate4()
//{
//	Date d;
//	return d;
//}
//
//Date TestDate5()
//{
//	return Date(2020, 8, 8);
//}
//
//int main()
//{
//	//TestDate4();
//	TestDate5();
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year=1900, int month=1, int day=1)
//	{
//		if (!(year > 0 &&
//			(month >= 1 && month <= 12) &&
//			(day > 0 && day <= GetDaysOfMonth(year, month))))
//		{
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//		else
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	// ִ�е���ǰ��++�Ĳ���
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	// ����++
//	// ע�⣺temp�Ǻ���ջ�ϵĶ��󣬵������˳�ʱ��temp��Ҫ��������
//	// ��˺���++�ĺ�������ֵ����ʹ�����õķ�ʽ���з����ˣ�ֻ�ܰ���ֵ�ķ�ʽ���з���
//	// ע�⣺�﷨Ϊ�����ֺ���++��ǰ��++��������ص����������ں���++�ĺ��������б��ж�������һ��int���͵Ĳ���
//	//      ǰ��++�ͺ���++�Ϳ����γɺ��������ˣ����Ǹ�int���Ͳ����ں������в�����ʹ�ã���˿��Բ��ø�����
//	//      ��Ȼ����++��ʵ��ʱ����һ��int���͵Ĳ����������û��ڵ���ʱ���ô��ݸ�intʵ��
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;
//	}
//	//ǰ��--
//	Date& operator--()
//	{
//		_day -= 1;
//		return *this;
//	}
//	//����--
//	Date operator--(int)
//	{
//		Date temp(*this);
//		_day -= 1;
//		return temp;
//	}
//
//	// ��=��������
//	// ����˵����Date d--->ȱ�� �ڴ����ڼ�Ҫ����һ����ʱ��������this���и�ֵ��Ч��̫����
//	//         Date& d---> �ŵ㣺�ڴ����ڼ��ٴ���һ����ʱ����Ч�ʸ���  ȱ�ݣ��ڸ�ֵ�ڼ䲻С�Ľ�d�޸��ˣ��ⲿʵ��Ҳ���޸���
//	//         const Date& d
//	// ����Ҫ�з���ֵ��Ŀ��Ϊ��֧��������ֵ
//	Date& operator=(const Date& d)
//	{
//		// �����Լ����Լ���ֵ
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	bool IsLeapYear(int year)
//	{
//		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
//		{
//			return true;
//		}
//		return false;
//	}
//	int GetDaysOfMonth(int year, int month)
//	{
//		int daysOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2 && IsLeapYear(year))
//			daysOfMonth[2] += 1;
//		return daysOfMonth[month];
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2020, 8, 8);
//	Date d2;
//	d2 = ++d1;
//	d2 = d1.operator++();
//
//	d2 = d1++;
//	d2 = d1.operator++(0);
//
//	Date d3;
//	d3 = d2 = d1;
//	d3.operator=(d2.operator=(d1));
//	return 0;
//}

// const���α�����
/*
��C�����У���const���ε���һ�����ܱ��޸ĵı���
���ԣ� const int  a = 10;   int array[a];

��C++�У���const���ε��Ѿ���һ�����������Ҿ��к��滻������
void TestConst()
{
const int a = 10;
int* pa = (int*)&a;

*pa = 100;
cout<<a<<endl;     // 10   ����a��ֵ�Ѿ���100  ԭ���ڱ���ڵ㣬�������Ѿ���a��10�滻��
cout<<*pa<<endl;   // 100
}

const���εĳ������滻�����ڱ���׶Σ������������ͼ�⣬����İ�ȫ�Ը���
���飺��C++��ʹ��const���εĳ�������곣��

/*
��C++�У�constҲ����������ĳ�Ա
1. const������ĳ�Ա�����������ó�Ա�������ܱ��޸ĵ�
2. const������ĳ�Ա����--->��Ϊconst���͵ĳ�Ա����

const���εĳ�Ա��������ͨ��Ա����������
*/
//class Date
//{
//public:
//	Date(int year=1900, int month=1, int day=1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// ��const���εĳ�Ա������Ϊconst���͵ĳ�Ա����
//	// const��Ա�����в����޸����"��Ա����"
//	// const�������ε��ǳ�Ա���������ص�thisָ��
//	// ��ʾ��thisָ��ָ��Ŀռ��е����ݲ����޸ģ�����thisָ��ǰ�������޸�
//	void PrintDate()const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		cout << typeid(this).name() << endl;
//	}
//	// const�ڷ���ֵ����֮ǰ�����εĸú����ķ���ֵ����
//	// ��ͨ��Ա�����У������޸�thisָ��ĵ�ǰ�����������Ϣ
//	const Date& GetDate()
//	{
//		cout << typeid(this).name() << endl;
//		_day++;
//		return *this;
//	}
//
//	// ���飺����ڳ�Ա�����в���Ҫ�޸ĳ�Ա����ʱ����Ա������ø���const��Ա��������Ϊ����İ�ȫ�Ը���
//	//      ���磺getϵ��
//	//      ����ڳ�Ա��������Ҫ�޸ĵ�ǰ����ĳ�Ա����һ�����ܸ���const��Ա�������������ʧ��
//	//      ���磺setϵ��
//
//	/*
//	C++�����Ի���
//	�����ϣ���const���εĳ�Ա�����в����޸��κε�"��Ա����"��������Щ����£�������Ҫ��const��Ա�������޸ĸ����Ա����
//	*/
//	void TestFunc()const
//	{
//		_day++;
//	}
//	Date* operator&()
//	{
//		cout << this << endl;
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	mutable int _day;
//	/*
//	mutable: ���ʺ����ʾ�ɱ��
//	���γ�Ա����ʱ�������ó�Ա����������const��Ա�����б��޸�
//	*/
//};
//int main()
//{
//	Date d1(2020, 8, 8);
//	d1.PrintDate();
//	d1.GetDate();
//	cout << &d1 << endl;
//
//	const Date d2(d1);
//	cout << &d2 << endl;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void PrintDate()const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//Date* const this
//	Date* operator&()
//	{
//		cout << this << endl;
//		return this;
//	}
//	// const���γ�Ա����������������thisָ��
//	// this�����ͣ�const Date* const this
//	const Date* operator&()const
//	{
//		return this;
//	}
//	void SetDay(int day)
//	{
//		_day = day;
//	}
//	int GetDay()const
//	{
//		return _day;
//	}
//	// const���͵ĳ�Ա����
//	void TestFuncWithConst()const
//	{
//		// const��Ա�����в��ܵ�����ͨ���͵ĳ�Ա����
//		// ��Ϊ��const��Ա����thisָ���������const  Date* const
//		// ������this����ĳ�Ա�ǲ����޸ĵ�
//		// �����this����SetDay����SetDay�����ڲ����ԶԵ�ǰ��������޸�
//		// ���´��벻��ȫ
//		// SetDay(10);
//		PrintDate();
//	}
//	// ��ͨ���͵ĳ�Ա����
//	// thisָ������ͣ�Date* const�������ö����еĳ�Ա�����޸�Ҳ���Բ��޸�
//	void TestFuncWithoutConst()
//	{
//		// SetDay: thisָ������ͣ�Date* const,�����ö����еĳ�Ա�����޸�Ҳ���Բ��޸�
//		// thisָ���������ȫƥ�䣬û���κ�����
//		SetDay(10);
//		// ���ۣ���ͨ��Ա�����п��Ե���const��Ա����
//		// ��Ϊ����ͨ��Ա����thisָ��Ķ����ǿɶ�д���ȿ����޸�Ҳ���Բ��޸�
//		//      ��const��Ա�����еĶ���ĳ�Ա�ǲ����޸ĵ�
//		// ����ͨ��Ա�����е���const���ͳ�Ա���������൱�ڽ�һ���ɶ�д�Ķ��󽻸�һ��ֻ���ĺ��������д�����
//		// ���뱾�����ǰ�ȫ��
//		PrintDate();
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	const Date d1(2020, 8, 8);
//	d1.PrintDate();
//
//	// d1��const���͵Ķ��󣬱�ʾ�ö���ĳ�Ա�ǲ������޸ĵ�
//	// ����const���Ͷ���������Ե�����ͨ���͵ĳ�Ա����������ͨ���͵ĳ�Ա�����п��ܻὫconst���Ͷ���ĳ�Ա�޸ĵ�
//	// ���벻��ȫ
//	// ��ˣ�const���͵Ķ���ֻ�ܵ���const���͵ĳ�Ա���������ܵ�����ͨ���͵ĳ�Ա����
//	// d1.SetDay(9);
//
//	// d2����ͨ���͵Ķ��󣬸ö����еĳ�Ա�����޸�Ҳ���Բ��޸�
//	// ��const���͵Ķ��������ͨ��Ա������const���͵ĳ�Ա���������Խ��е���
//	Date d2(2020, 8, 8);
//	d2.SetDay(9);
//	cout << d2.GetDay() << endl;
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date&):" << this << endl;
	}
	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
Date TestDate1(Date d)
{
	Date temp(d);
	temp = d;
	return temp;
}
void Test1()
{
	Date d1(2020, 8, 8);
	Date d2(2020, 8, 9);
	d1 = TestDate1(d2);
}
Date& TestDate2(Date& d)
{
	Date temp(d);
	temp = d;
	return d;
}
void Test2()
{
	Date d1(2020, 8, 8);
	Date d2(2020, 8, 9);
	d1 = TestDate2(d2);
}
int main()
{
	//Test1();
	Test2();
	return 0;
}