#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
namespace bite
{
	//T:类型参数
	//N:非类型参数 &具有const属性--是一个常量
	template<class T,size_t N=10>
	class array
	{
	public:
		array()
			: _size(0)
		{}

		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < _size);
			return _array[index];
		}

		size_t size()const
		{
			return _size;
		}
	private:
		T _array[N];
		size_t _size;
	 };
}

int main()
{
	bite::array<int> a1;
	return 0;
}
#endif

// 函数模板可能对于某些特殊类型不能处理，或者处理的逻辑是有问题的
// 因此：需要将该模板针对于该种类型来进行特殊处理
// 特化

// 如果要对模板进行特化：
// 1. 先要有模板的代码
// 2. 该份模板类型的代码对于那种类型不能处理
// 3. 用该类型去特化该模板

#include <string.h>
template<class T>
T Max(T left, T right)
{
	return left > right ? left : right;
}

char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

int main()
{
	cout << Max(10, 20) << endl;
	cout << Max(1.2, 3.4) << endl;

	char* p1 = "hello";
	char* p2 = "World";
	cout << Max(p1, p2) << endl;
	return 0;
}