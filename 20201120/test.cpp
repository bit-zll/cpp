#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
int main()
{
	FILE* pf = fopen("1.txt", "wb");
	if (NULL == pf)
	{
		exit(0);
	}

	int a = 12345678;
	char sz[32] = { 0 };
	_itoa(a, sz, 10);
	fwrite(sz, 1, strlen(sz), pf);

	char ch = -1;
	memset(sz, 0, 32);

	_itoa(ch, sz, 10);
	fwrite(sz, 1, strlen(sz), pf);
	fclose(pf);
	return 0;
}
#endif

#if 0
int main()
{
	int a = 12345678;
	char sz[32] = { 0 };
	_itoa(a, sz, 10);

	memset(sz, 0, 32);
	sprintf(sz, "%d", a);
	return 0;
}
#endif

#include <sstream>

#if 0
int main()
{
	int a = 12345678;
	stringstream ss;
	ss << a;

	string str;
	ss >> str;
	string ret = ss.str();

	ss.clear();
	ss.str("");
	double d = 12.34;
	ss << d;
	ss >> str;

	ret = ss.str();
	cout << ret << endl;
	return 0;
}
#endif

#if 0
int main()
{
	stringstream ss;
	ss << "hello";
	ss << " ";
	ss << "world!!!";

	string s;
	s = ss.str();
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main()
{
	unsigned long long a = 0xffffffff;
	cout << a << endl;
	return 0;
}
#endif

#if 0
#include <string>
//基类/父类
class Person
{
public:
	void Eat()
	{
		cout << "biajibiaji" << endl;
	}

	void Sleep()
	{
		cout << "huluhulu" << endl;
	}
private:
	string _name;
	string _gender;
	int _age;
};

//派生类/子类
class Student : public Person
{
public:
	void Study()
	{
		cout << "念书" << endl;
	}
private:
	int _stuid;
};

int main()
{
	Student s;
	s.Eat();
	s.Sleep();

	cout << sizeof(Student) << endl;
	return 0;
}
#endif

#if 0
#include <string>
//基类/父类
class Person
{
public:
	void Eat()
	{
		cout << "biajibiaji" << endl;
	}

	void Sleep()
	{
		cout << "huluhulu" << endl;
	}

private:
	//既不能在类外直接使用
	//也不允许在子类中直接使用
	string _name;
	string _gender;

protected:
	//不能在类外直接使用
	//但是可以在子类中使用
	int _age;
};

//派生类/子类
class Student : public Person
{
public:
	void Study()
	{
		//基类中protected成员在子类中乐意直接使用
		//权限：protected
		_age = 18;

		//基类中private修饰的成员在子类中不可见（不能直接使用）
		//_name = "lily";
		cout << "念书" << endl;
	}
private:
	int _stuid;
};

class A : public Student
{
public:
	void Test()
	{
		_age = 10;
	}
};

int main()
{
	Student s;
	//基类public成员在子类中的访问权限也是public
	s.Eat();
	s.Sleep();

	cout << sizeof(Student) << endl;
	return 0;
}
#endif;

#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : protected Base
{
public:
	void test()
	{
		//基类中public修饰成员在子类中的权限变成protected
		_pub = 10;

		//基类中protected修饰的成员在子类中的权限也是protected
		_pro = 10;

		//基类中private修饰的成员在子类中不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	//d._pub = 1;
	return 0;
}
#endif 

// 赋值兼容规则---前提：必须是public继承方式
// 1. 子类对象可以给基类对象赋值，反过来不行
// 2. 基类值指针或者引用可以直接指向子类的对象
// 3. 子类的指针不能直接指向基类的对象

/*
如果是public的继承方式：
子类和基类的关系：is-a(是一个) 可以将子类对象看成是一个基类对象
对象模型：对象中成员在内存中的分布形式
*/

#if 0
class Person
{
public:
	void Eat()
	{
		cout << "biajibiaji" << endl;
	}

	void Sleep()
	{
		cout << "huluhulu" << endl;
	}

	string _name;
	string _gender;

private:
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "念书" << endl;
	}


	int _stuid;
};

int main()
{
	//1.子类对象可以给基类对象赋值，反过来不行
	Person p;
	Student s;
	p = s;
	//s = p;

	//2.基类值指针或者引用可以直接指向子类的对象
	Person* pp = &s;
	Person& rp = s;

	// 3. 子类的指针不能直接指向基类的对象,但是强转可以---不安全
	Student* ps = (Student*)&p;
	ps->_name = "lily";
	ps->_gender = "男";
	//ps->_age = 18;
	ps->_stuid = 100;
	return 0;
}
#endif

class Base
{
public:
	void Set(int b)
	{
		_b = 10;
	}
private:
	int _b;
};

class Derive : public Base
{
public:
	void Set()
	{
		Base::Set(10);
		__super::Set(10);
		_d = 100;
	}
private:
	int _d;
};

int main()
{
	Derive d;
	d.Base::Set(10);
	return 0;
}