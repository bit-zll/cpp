#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include <string>

#if 0
int main()
{
	string s("12345");
	int value = atoi(s.c_str());
	cout << value << endl;
	cout << sizeof(string) << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello");
	string s2("world");
	if (s1 > s2)
		cout << "s1<s2" << endl;
	else
		cout << "s1>=s2" << endl;

	cout << 10 << "   " << 20 << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s;
	//getline(cin, s);
	//cout << s << endl;
	while (getline(cin, s))
	{
		cout << s << endl;
	}
	return 0;
}
#endif

#include <algorithm>
#if 0
int main()
{
	string s("hello");
	reverse(s.begin(), s.end());
	sort(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello");
	//遍历方式1
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i] <<" ";
	cout << endl;
	//遍历方式2
	for (auto e : s)
		cout << e << " ";
	cout << endl;
	//遍历方式3
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//遍历方式4
	//string::reverse_iterator rit = s.rbegin();
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;
}
#endif

int main()
{
	string s("Hello");
	for (auto& e : s)
	{
		if (e >= 'A'&&e <= 'Z')
			e += 32;
	}
	return 0;
}