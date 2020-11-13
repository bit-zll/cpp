#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include <queue>
#include <vector>
#include <functional>

#if 0
int main()
{
	//默认按照小于进行比较（大堆）
	priority_queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	q1.pop();
	cout << q1.top() << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());

	cout << q2.top() << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}

	int _year;
	int _month;
	int _day;
};

void TestPriorityQueue1()
{
	Date d1(2020, 11, 12);
	Date d0(2020, 11, 11);
	Date d2(2020, 11, 13);

	priority_queue<Date> q1;
	q1.push(d1);
	q1.push(d0);
	q1.push(d2);
}

// 仿函数/函数对象---可以像函数一样使用的对象
//  原理：只需要在类中将()重载一下
// ()称为函数调用运算符
// 作用：定制算法功能

class Greater
{
public:
	bool operator()(const Date* left, const Date* right)
	{
		return left->_day > right->_day;
	}
};

bool gg(const Date* left, const Date* right)
{
	return left->_day > right->_day;
}
int main()
{
	Date* p1 = new Date(2020, 11, 12);
	Date* p2 = new Date(2020, 11, 11);
	Date* p3 = new Date(2020, 11, 13);

	Greater g;
	g(p1, p2);//函数调用，g是一个对象
	gg(p1, p2);//函数调用，gg是一个函数名

	priority_queue<Date*, vector<Date*>, Greater> q1;
	q1.push(p1);
	q1.push(p2);
	q1.push(p3);
	return 0;
}
#endif

#if 0
struct Goods
{
	Goods(const string& name,double price)
		: _name(name)
		, _price(price)
	{}

	bool operator<(const Goods& g)const
	{
		return _price < g._price;
	}
	bool operator>(const Goods g)const
	{
		return _price > g._price;
	}
	string _name;
	double _price;
};

struct Greater
{
	bool operator()(const Goods& g1, const Goods& gr)
	{
		return g1._price > gr._price;
	}
};

#include <algorithm>

int main()
{
	//默认按照升序比较
	vector<int> v{ 2, 5, 0, 8, 1, 7, 6, 4, 3, 9 };
	sort(v.begin(), v.end());

	//按照降序比较
	sort(v.begin(), v.end(), greater<int>());

	Goods gs[] = { { "apple", 2.5 }, { "banana", 1.8 }, { "orange", 3.2 } };

	sort(gs, gs + sizeof(gs) / sizeof(gs[0]));
	sort(gs, gs + sizeof(gs) / sizeof(gs[0]), Greater());
	return 0;
}
#endif

#include "PriorityQueue.h"

int main()
{
	vector<int> v{ 3, 2, 5, 1, 4 };
	bite::priority_queue<int> q{ v.begin(),v.end() };
	q.push(0);
	return 0;
}