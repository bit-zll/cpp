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
	// e是对v6中每个元素的引用
	for (auto& e : v6)
		e *= 2;

	// e是v6中每个元素的一份拷贝
	// 注意：范围for的原理与采用正向迭代器的原理是完全相同的
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
	// 注意：使用front和back访问vector中元素时，vector一定不能为空
	cout << v.front() << endl;
	cout << v.back() << endl;
}

void TestVector6()
{
	// 注意：push_back和insert在插入元素期间，可能需要扩容
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.pop_back();

	v.insert(v.begin(), 0);

	// 在元素2的位置插入10个值为5的元素
	v.insert(find(v.begin(), v.end(), 2), 10, 5);

	//将数组array中的元素插入到v的尾部
	int array[] = { 4, 5, 6, 7 };
	v.insert(v.end(), array, array + sizeof(array) / sizeof(array[0]));
}

// 插入自定义类型的元素:最终插入的是一份拷贝
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

	// it1指向v1原来空间的起始位置
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	// v1底层的空间已经发生改变
	v1.swap(v2);

	// 没有失效
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
		it++;//迭代器失效
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