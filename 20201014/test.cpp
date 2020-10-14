#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
	}
	~Test()
	{
		cout << "~Test(int t):" << this << endl;
	}
private:
	int _t;
};
int main()
{
	//Test* pt1 = new Test;
	//Test* pt2 = new Test();
	//Test* pt3 = new Test(20);

	//delete pt1;
	//delete pt2;
	//delete pt3;

	Test* pt = new Test[10];

	delete[] pt;
	return 0;
}
#endif

class Test
{
public:
	Test(int t = 10)
		: _t(t)
	{
		cout << "Test(int t):" << this << endl;
	}
	~Test()
	{
		cout << "~Test(int t):" << this << endl;
	}
private:
	int _t;
};
int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test(100);

	free(pt);
	return 0;
}