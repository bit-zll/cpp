#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//1+2+3+...+n
//class Sum
//{
//public:
//	Sum()
//	{
//		count++;
//		sum += count;
//	}
//
//	static void Reset()
//	{
//		count = 0;
//		sum = 0;
//	}
//	static int GetSum()
//	{
//		return sum;
//	}
//private:
//	static int count;//���������ӵ�ÿһ��
//	static int sum;//�����ۻ����ӵĽ��
//};
//
//int Sum::count = 0;
//int Sum::sum = 0;
//
//int main()
//{
//	Sum s1[3];
//	cout << Sum::GetSum() << endl;
//	Sum::Reset();
//	Sum s2[5];
//	cout << Sum::GetSum() << endl;
//	return 0;
//}

//int main()
//{
//	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		int totalDays = 0;
//		for (int i = 1; i < month; ++i)
//		{
//			totalDays += days[i];
//		}
//		if ((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
//		{
//			if (month > 2)
//				totalDays += 1;
//		}
//
//		totalDays += day;
//		cout << totalDays << endl;
//	}
//
//	return 0;
//}


//��Ŀ��һ���ж������
//����������һ������
int main()
{
	char sz[1024] = { 0 };
	//ע�⣺�����Ҫ����һ�����ַ���������£�����ֱ��ʹ��scanf��cin
	//��Ϊscanf��cin�����ո��ֹͣ���ܣ��ո�֮������ݽ��ܲ���
	while (gets(sz))
	{
		//ʵ�ʴӺ���ǰ�ң��ҵ���һ���ո�Ϳ���
		int i = strlen(sz);
		for (; i >= 0; i--)
		{
			if (sz[i] == ' ')
				break;
		}

		//����һ��ֻ��һ�����ʣ����о�û�пո�
		if (i < 0)i = 0;
		cout << sz + i + 1 << endl;
	}

	return 0;
}
//������
//class Date
//{
//public:
//	Date(int year =1900 , int month =1, int day =1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		if (!((year > 0) &&
//			(month >= 1 && month <= 12) &&
//			(day >= 1 && day <= GetDaysOfMonth(year,month))))
//		{
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//	}
//	int GetDaysOfMonth(int year, int month)
//	{
//		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2)
//		{
//			if (isLeapYear(year))
//				days[2] += 1;
//		}
//		return days[month - 1];
//	}
//	bool isLeapYear(int year)
//	{
//		if (0 == year % 4 && 0 != year % 100 || (0 == year % 400))
//		{
//			return true;
//		}
//		return false;
//	}
//	/*three big  ����Ҫôͬʱ���֣�Ҫô��������*/
//	/*Date(const Date& d)
//		: _year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	~Date()
//	{}*/
//
//	bool operator>(const Date& d)const
//	{
//		if ((_year > d._year) ||
//			(_year == d._year&&_month > d._month) ||
//			(_year == d._year&&_month == d._month&&_day > d._day))
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool operator==(const Date& d)const
//	{
//		return _year == d._year&&
//			_month == d._month&&
//			_day == d._day;
//	}
//
//	bool operator!=(const Date& d)const
//	{
//		return !(*this == d);
//	}
//
//	bool operator>=(const Date& d)const
//	{
//		if (*this > d || *this == d)
//			return true;
//		return false;
//	}
//
//	bool operator<(const Date& d)const
//	{
//		if (!(*this > d || *this == d))
//			return true;
//		return false;
//	}
//
//	bool operator<=(const Date& d)const
//	{
//		if (*this < d || *this == d)
//			return true;
//		return false;
//	}
//
//	Date operator+(int days)
//	{
//		if (days<0)
//		{
//			return *this - (0 - days);
//		}
//		Date temp(*this);
//		temp._day += days;
//
//		int daysOfMonth = 0;
//		while (temp._day > (daysOfMonth = temp.GetDaysOfMonth(temp._year, temp._month)))
//		{
//			temp._month += 1;
//			if (temp._month > 12)
//			{
//				temp._year += 1;
//				temp._month = 1;
//			}
//			temp._day -= daysOfMonth;
//		}
//		return temp;
//	}
//	Date operator-(int days)
//	{
//		if (days < 0)
//		{
//			return *this + (0 - days);
//		}
//		Date temp(*this);
//		temp._day -= days;
//
//		while (temp._day <= 0)
//		{
//			temp._month -= 1;
//			if (temp._month == 0)
//			{
//				temp._year -= 1;
//				temp._month = 12;
//			}
//			temp._day += temp.GetDaysOfMonth(temp._year, temp._month);
//		}
//		return temp;
//	}
//	//ǰ��++
//	Date& operator++()
//	{
//		*this = *this + 1;
//		return *this;
//	}
//
//	//����++
//	Date operator++(int)
//	{
//		Date temp(*this);
//		*this = *this + 1;
//		return temp;
//	}
//
//	//ǰ��--
//	Date& operator--()
//	{
//		*this = *this - 1;
//		return *this;
//	}
//
//	//����--
//	Date operator--(int)
//	{
//		Date temp(*this);
//		*this = *this - 1;
//		return temp;
//	}
//
//	//*this��d֮��Ĳ�ֵ
//	int operator-(const Date& d)
//	{
//		Date minDate(*this);
//		Date maxDate(d);
//		if (minDate > maxDate)
//		{
//			minDate = d;
//			maxDate = *this;
//		}
//		int count = 0;
//		while (minDate != maxDate)
//		{
//			count++;
//			minDate++;
//		}
//		return count;
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//int main()
//{
//	Date d1(2020, 10, 8);
//	Date d2(2020, 1, 1);
//	cout << d1 - d2 << endl;
//	//Date d3(2020, 15, 300);
//
//	//d2 = d1 - 100;
//	//cout << d1 << endl;
//	//cout << d2 << endl;
//	//cout << d3 << endl;
//	return 0;
//}