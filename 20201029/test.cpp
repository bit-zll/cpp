#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include <string.h>

#if 0
//反例
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			_str = new char[1];
			*_str = '0';
		}
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		/*
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		*/
	}

	//编译器生成的默认拷贝构造函数---浅拷贝
	String(const String& s)
		: _str(s._str)
	{ }

	//编译器生成的默认赋值运算符重载---浅拷贝
	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	String s3("hello");
	s1 = s3;
	return 0;
}
#endif

#if 0
//方式1
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2(s1);
	String s3("world");
	s1 = s3;
	return 0;
}
#endif
//方式2
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
	{
		String strTemp(s._str);
		swap(_str, strTemp._str);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2(s1);
	String s3("abc");
	s1 = s3;
}

int main()
{
	TestString();
	return 0;
}