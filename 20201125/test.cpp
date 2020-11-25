#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
class Base
{
public:
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	void TestFunc(int b)
	{
		Base::_b = 100;
		__super::_b = 10;//����ͬ��
		cout << "Derived::TestFunc()" << endl;
	}

	int _b;
};

int main()
{
	Derived d;
	d.TestFunc(10);
	d.Base::TestFunc();
	d.Base::_b = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	void TestFunc(int b)
	{
		Base::_b = 100;
		__super::_b = 10;//����ͬ��
		cout << "Derived::TestFunc()" << endl;
	}

protected:
	int _d;
};

int main()
{
	Derived d;
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)// ��ʼ�����ಿ�ּ̳������ĳ�Ա
		, _d(d)
	{
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

protected:
	int _d;
};

void TestFunc()
{
	Derived d(1, 2);
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b = 10)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	/*
	����û�û����ʽ����������������Զ�����һ��Ĭ�ϵĹ��캯��
	Derived()
	: Base(10)
	, _d(0xCCCCCCCC)  // ջ�ϵĶ���
	{
	cout << "Derived()" << endl;
	}
	*/
	~Derived()
	{
		cout << "~Derived()" << endl;
	}

protected:
	int _d;
};
#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}

		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b,int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

protected:
	int _d;
};

int main()
{
	Derived d1(1, 2);
	Derived d2(3, 4);

	d1 = d2;
	return 0;
}
#endif

#if 0
class Base
{
	friend void TestFriend();
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}

		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};


class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};


void TestFriend()
{
	Base b(1);
	b._b = 10;

	Derived d(1, 2);
	d._d = 100;
}
#endif

#if 0
class Base
{
	friend void TestFriend();
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}
		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;

public:
	static int c;
};

int Base::c = 0;

class Derived : public Base
{
public:
	Derived(int b,int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}
		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

protected:
	int _d;
};

int main()
{
	cout << sizeof(Derived) << endl;
	Base::c = 1;
	Derived::c = 2;
	cout << &Base::c << " " << &Derived::c << endl;
	return 0;
}
#endif

#if 0
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

class D : public B2, public B1
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif

#if 0
class B
{
public:
	void TestFunc()
	{}

	int _b;
};

//���̳�
class C1 : public B
{
public:
	int _c1;
};

//���̳�
class C2 : public B
{
public:
	int _c2;
};

//��̳�
class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	D d;
	d.C1::_b = 1;
	d._c1 = 2;
	d.C2::_b = 3;
	d._c2 = 4;
	d._d = 5;

	d.C1::TestFunc();
	return 0;
}
#endif

// ���һ����û����ʽ�����κι��캯��
// ������Ҳ��һ��������

// ������ʲô����»����ɹ��캯����
// �𰸣��������о��Լ���Ҫ��ʱ�������

class B
{
public:
	int _b;
};

//����̳�
class D : virtual public B
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	B b;
	D d;
	d._b = 1;
	d._d = 2;
	return 0;
}