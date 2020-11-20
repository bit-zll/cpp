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
//����/����
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

//������/����
class Student : public Person
{
public:
	void Study()
	{
		cout << "����" << endl;
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
//����/����
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
	//�Ȳ���������ֱ��ʹ��
	//Ҳ��������������ֱ��ʹ��
	string _name;
	string _gender;

protected:
	//����������ֱ��ʹ��
	//���ǿ�����������ʹ��
	int _age;
};

//������/����
class Student : public Person
{
public:
	void Study()
	{
		//������protected��Ա������������ֱ��ʹ��
		//Ȩ�ޣ�protected
		_age = 18;

		//������private���εĳ�Ա�������в��ɼ�������ֱ��ʹ�ã�
		//_name = "lily";
		cout << "����" << endl;
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
	//����public��Ա�������еķ���Ȩ��Ҳ��public
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
		//������public���γ�Ա�������е�Ȩ�ޱ��protected
		_pub = 10;

		//������protected���εĳ�Ա�������е�Ȩ��Ҳ��protected
		_pro = 10;

		//������private���εĳ�Ա�������в��ɼ�
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

// ��ֵ���ݹ���---ǰ�᣺������public�̳з�ʽ
// 1. ���������Ը��������ֵ������������
// 2. ����ֵָ��������ÿ���ֱ��ָ������Ķ���
// 3. �����ָ�벻��ֱ��ָ�����Ķ���

/*
�����public�ļ̳з�ʽ��
����ͻ���Ĺ�ϵ��is-a(��һ��) ���Խ�������󿴳���һ���������
����ģ�ͣ������г�Ա���ڴ��еķֲ���ʽ
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
		cout << "����" << endl;
	}


	int _stuid;
};

int main()
{
	//1.���������Ը��������ֵ������������
	Person p;
	Student s;
	p = s;
	//s = p;

	//2.����ֵָ��������ÿ���ֱ��ָ������Ķ���
	Person* pp = &s;
	Person& rp = s;

	// 3. �����ָ�벻��ֱ��ָ�����Ķ���,����ǿת����---����ȫ
	Student* ps = (Student*)&p;
	ps->_name = "lily";
	ps->_gender = "��";
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