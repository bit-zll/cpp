#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
namespace bite
{
	//T:���Ͳ���
	//N:�����Ͳ��� &����const����--��һ������
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

// ����ģ����ܶ���ĳЩ�������Ͳ��ܴ������ߴ�����߼����������
// ��ˣ���Ҫ����ģ������ڸ����������������⴦��
// �ػ�

// ���Ҫ��ģ������ػ���
// 1. ��Ҫ��ģ��Ĵ���
// 2. �÷�ģ�����͵Ĵ�������������Ͳ��ܴ���
// 3. �ø�����ȥ�ػ���ģ��

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