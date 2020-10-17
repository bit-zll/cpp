#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

void TestString1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	string s4(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	cin >> s1;
	cout << s1 << endl;
}

void TestString2()
{
	string s1("hello");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}

	s1.clear();
	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}
}

void TestString3()
{
	string s1("hello");

	// 将s1中有效字符增加到10个，多出的5个字符使用'!'来进行填充
	s1.resize(10,'!');

	// 将s1中有效字符增加到32个，多出的22个字符使用'$'来进行填充
	// 在增加字符期间会进行扩容
	s1.resize(32, '$');

	// 当resize将有效元素个数减少时，只修改有效元素个数，而不会缩小底层空间的大小
	s1.resize(28);

	s1 += "world";
	cout << s1 << endl;
}

void TestString4()
{
	string s1("hello");
	cout << sizeof(s1) << endl;

	// 将容量增大
	s1.reserve(10);
	s1.reserve(21);   
	s1.reserve(28);
	s1.reserve(40);

	// 将容量缩小
	s1.reserve(32);
	s1.reserve(20);
	s1.reserve(13);
}

void TestString5()
{
	string s1("hello");
	cout << s1[0] << endl;

	s1[0] = 'H';
	cout << s1[0] << endl;
}

void TestString6()
{
	string s1("hello");
	
	s1.push_back(',');
	s1 += "world";
	cout << s1 << endl;

	string s2("!!!");
	s1 += s2;
	s1 += '$';
	cout << s1 << endl;

	s1.append(1, '%');
	cout << s1 << endl;

	s1.append(s1, 2, 3);
	cout << s1 << endl;
}

void TestString7()
{
	string s1("hello world !!!");
	s1.insert(s1.find(' '), "$$$");
	cout << s1 << endl;
}

// 给一行单词(该行可能有多个单词，单词和单词之间使用空格隔开，求最后一个单词的长度)
void TestString8()
{
	string s;
	getline(cin, s);
	cout << s << endl;
	cout << s.substr(s.rfind(' ') + 1) << endl;
	cout << s.substr(s.rfind(' ') + 1).size() << endl;
}
int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	TestString8();
	return 0;
}