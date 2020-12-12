#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include <string>
#if 0
class Base
{
public:
	void f0()
	{
		cout << "Base::f0()" << endl;
	}

	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	virtual void f3()
	{
		_b = 10;
		cout << "Base::f3()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	void f0()
	{
		cout << "Base::f0()" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f5()" << endl;
	}

	int _d;
};
#endif

#include "BSTree.hpp"

int main()
{
	TestBSTree();
	return 0;
}