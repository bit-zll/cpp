#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include <vector>
#include <string>

void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10,5);
	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string s("hello");
	vector<char> v4(s.begin(), s.end());

	vector<int> v5(v3);

	auto rit = v5.rbegin();
	while (rit != v5.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	vector<int> v6{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	// e�Ƕ�v6��ÿ��Ԫ�ص�����
	for (auto& e : v6)
		e *= 2;

	// e��v6��ÿ��Ԫ�ص�һ�ݿ���
	// ע�⣺��Χfor��ԭ������������������ԭ������ȫ��ͬ��
	for (auto e : v6)
		cout << e << " ";
	cout << endl;
}

class A
{
public:
	A(int a = 10)
		: _a(a)
	{}

	A(const A& a)
		: _a(a._a)
	{
		cout << "A(const A&)" << endl;
	}
private:
	int _a;
};

void TestVector3()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.resize(5);
	v.resize(7, 100);
	v.resize(9);
	v.resize(20, 50);

	vector<int> v1(10);
	vector<A> v2(10);
}
void TestVector2()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	if (v.empty())
	{
		cout << "v empty" << endl;
	}
	else
	{
		cout << "v not empty" << endl;
	}
}

void TestVector4()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.reserve(5);
	v.reserve(30);
	v.reserve(25);
	v.reserve(40);
}

void TestVector5()
{
	vector<int> v{ 1, 2, 3 };
	cout << v.front() << endl;
	cout << v.back() << endl;
	v.clear();
	// ע�⣺ʹ��front��back����vector��Ԫ��ʱ��vectorһ������Ϊ��
	cout << v.front() << endl;
	cout << v.back() << endl;
}

void TestVector6()
{
	// ע�⣺push_back��insert�ڲ���Ԫ���ڼ䣬������Ҫ����
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.pop_back();

	v.insert(v.begin(), 0);

	// ��Ԫ��2��λ�ò���10��ֵΪ5��Ԫ��
	v.insert(find(v.begin(), v.end(), 2), 10, 5);

	//������array�е�Ԫ�ز��뵽v��β��
	int array[] = { 4, 5, 6, 7 };
	v.insert(v.end(), array, array + sizeof(array) / sizeof(array[0]));
}

// �����Զ������͵�Ԫ��:���ղ������һ�ݿ���
void TestVector7()
{
	A a;
	vector<A> v;
	v.reserve(10);
	v.push_back(a);
}

void TestVector8()
{
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}
	}
}

void TestVector9()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 3);

	auto it = v.begin();
	while (it != v.end());
	{
		v.erase(it);
		it++;
	}
}

void TestVector10()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 4, 5, 6, 7, 8, 9 };

	// it1ָ��v1ԭ���ռ����ʼλ��
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	// v1�ײ�Ŀռ��Ѿ������ı�
	v1.swap(v2);

	// û��ʧЧ
	cout << *it1 << endl;
	cout << *it2 << endl;

	it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
}

void TestVector11()
{
	vector<int> v{ 1, 2, 3 };
	auto it = v.begin();

	v.clear();
	cout << *it << endl;

	while (it != v.end())
	{
		it = v.erase(it);
		it++;//������ʧЧ
	}
}
int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//TestVector6();
	//TestVector7();
	//TestVector8();
	//TestVector9();
	//TestVector10();
	TestVector11();
	return 0;
}