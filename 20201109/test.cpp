#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#include <stack>

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.top() = 5;
	cout << s.top() << endl;

	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	return 0;
}