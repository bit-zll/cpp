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
		cout << "���ַ���" << endl;
	}
	else
	{
		cout << "�ǿ��ַ���" << endl;
	}

	s1.clear();
	if (s1.empty())
	{
		cout << "���ַ���" << endl;
	}
	else
	{
		cout << "�ǿ��ַ���" << endl;
	}
}

void TestString3()
{
	string s1("hello");

	// ��s1����Ч�ַ����ӵ�10���������5���ַ�ʹ��'!'���������
	s1.resize(10,'!');

	// ��s1����Ч�ַ����ӵ�32���������22���ַ�ʹ��'$'���������
	// �������ַ��ڼ���������
	s1.resize(32, '$');

	// ��resize����ЧԪ�ظ�������ʱ��ֻ�޸���ЧԪ�ظ�������������С�ײ�ռ�Ĵ�С
	s1.resize(28);

	s1 += "world";
	cout << s1 << endl;
}

void TestString4()
{
	string s1("hello");
	cout << sizeof(s1) << endl;

	// ����������
	s1.reserve(10);
	s1.reserve(21);   
	s1.reserve(28);
	s1.reserve(40);

	// ��������С
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

// ��һ�е���(���п����ж�����ʣ����ʺ͵���֮��ʹ�ÿո�����������һ�����ʵĳ���)
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