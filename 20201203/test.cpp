#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "普通票" << endl;
	}
};

class Student :public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
};

// 在编译阶段，编译器无法确定到底要调用那个类的虚函数
// 只有在程序运行时，知道pb指向那个类的对象，然后调用对应的类的虚函数
void TestVirtual(Person* pb)
{
	pb->BuyTicket();
}

int main()
{
	Person p;
	Student s;
	TestVirtual(&p);
	TestVirtual(&s);
	return 0;
}
#endif

#if 0
class A
{
public:
	A(int a)
		: _a(a)
	{}

	virtual ~A()
	{
		cout << "~A()" << endl;
	}
protected:
	int _a;
};

class B :public A
{
public:
	B(int a, int b)
		: A(a)
		, _b(b)
	{
		_p = new int[10];
	}
private:
	~B()
	{
		delete[] _p;
	}
protected:
	int _b;
	int* _p;
};

int main()
{
	A* pa = new B(1, 2);
	delete pa;
	pa = nullptr;
	return 0;
}
#endif

#if 0
// override: C++11新增加的关键字，让编译器编译器阶段替用户检测子类是否将基类虚函数重写成功
//   重写成功：编译通过
//   重写失败：编译失败
class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	virtual void f1()final//final 不想让子类继承f1函数
	{
		cout << "Base::f1()" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void TestFunc()override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}
};

void TestVirtual(Base& b)
{
	b.TestFunc();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
#endif

#if 0
//A不让继承
class A
{
public:
	A(int a)
		: _a(a)
	{}
protected:
	int _a;
};

class B : public A
{};
#endif

#if 0
class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}
	virtual Base* f2()
	{
		cout << "Base::f2()" << endl;
		return this;
	}
	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}
	void f4()
	{
		cout << "Base::f4()" << endl;
	}
	void f5()
	{
		cout << "Base::f5(）" << endl;
	}
	virtual int f6()
	{
		cout << "Base::f6()" << endl;
		return 0;
	}
	int f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}
};

class Derived : public Base
{
public:
	//重写
	virtual void f1()
	{
		cout << "Derive::f1()" << endl;
	}

	virtual Derived* f2()
	{
		cout << "Derived::f2()" << endl;
		return this;
	}

	//同名隐藏
	virtual void f3(int)
	{
		cout << "{Derived::f3(int)" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	char f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}
};
#endif

#if 0
#include <Windows.h>

class WashRoom
{
public:
	void ManWC()
	{
		cout << "go to left" << endl;
	}

	void WomanWC()
	{
		cout << "go to right" << endl;
	}
};

//抽象类
class Person
{
public:
	//纯虚函数
	virtual void GotoWC(WashRoom& wc) = 0;
};

// 抽象类是一定要被继承的
// 子类继承一个抽象类之后，如果没有重写基类的纯虚函数，则子类也是抽象类
class Man : public Person
{
public:
	virtual void GotoWC(WashRoom& wc)
	{
		wc.ManWC();
	}
};

class Woman : public Person
{
public:
	virtual void GotoWC(WashRoom& wc)
	{
		wc.WomanWC();
	}
};

void TestWC()
{
	//厕所门口收钱的
	Person* p = nullptr;
	WashRoom wr;
	for (size_t i = 0; i < 10; ++i)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}

		p->GotoWC(wr);
		delete p;

		Sleep(3000);
	}
}

int main()
{
	// Person p;  编译失败：抽象类不能实例化对象
	Man m;
	TestWC();
	return 0;
}
#endif

class Base
{
public:
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
		cout << "Base::f3()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}
	int _d;

};

#include <string>

typedef void(*PVF)();

void PrintfVFT(Base& b, const string& info)
{
	PVF* pVFT = (PVF*)(*(int*)(&b));
	cout << info << endl;
	while (*pVFT)
	{
		*pVFT = nullptr;
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;
	Base b, b1, b2;
	b._b = 1;
	PrintfVFT(b, "base virtual function table:");

	Derived d;
	d._b = 1;
	d._d = 2;
	PrintfVFT(d, "Derived virtual function table:");

	return 0;
}