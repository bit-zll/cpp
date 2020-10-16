#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#if 0
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1.2, 2.3);
	Add('1', '2');
	return 0;
}
#endif

#if 0
//Add����ģ��
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

int main()
{
	//��ģ�����ʵ����
	Add(10, 20);    //10,20--->int
	Add(1.2, 2.3);  //1.2,2.3--->double
	Add('1', '2');  //'1','2'--->char
}
#endif

template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}

#if 0
//�������͵�����
template<class T>
void PrintArray(T array[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int array1[] = { 1, 2, 3, 4, 5 };
	PrintArray(array1, sizeof(array1) / sizeof(array1[0]));

	double array2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	PrintArray(array2, sizeof(array2) / sizeof(array2[0]));
	return 0;
}
#endif

#if 0
//����ģ�岻��һ������������һ��������ģ��
template<typename T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}


//ģ���ʵ������Ҳ���ǽ�����ģ��������廯
// ����ģ�����ԭ��---��ʽʵ����
//  �������ڱ���׶Σ��û��Ժ���ģ��ʵ����֮��
//  ���������ʵ�����ͽ������ݣ�
//  �������ݵĽ����ȷ��ģ������б���T��ʵ������
//  ����ȷ����T�ľ������������ɴ���������͵ĺ���
// ע�⣺����ʽʵ�����У������������ɴ���ʱ���������ʽ����ת��

int main()
{
	//��ʽʵ����
	Add(1, 2);
	/*
	int Add<int>(int left,int right)
	{
		cout<<typeid(int).name()<<endl;
		return left+right;
	}
	*/
	Add(1.0, 2.0);
	/*
	double Add<double>(double left,double right)
	{
		cout<<typeid(double).name()<<endl;
		return left+right;
	}
	*/

	//int��double֮������໥ת��
	Add(1, (int)2.0); //int double

	// ��ʽʵ����
	// �������ڱ�������ڼ䣬�����Ժ���ģ�������ʾʵ����֮��
	// ֱ�Ӹ�����ʽʵ������T�ľ�������ֱ�����ɴ��룬
	// �ھ������ʱ���ܻ������ʽ����ת��
	Add<int>(1, 2.0);
	Add<double>(1, 2.0);
	return 0;
}
#endif

#if 0
template<class T,class U>
T Add(T left, U right)
{
	return left + right;
}

int main()
{
	Add(1, 2.0);
	/* 
	int Add<int,double>(int left,double right)
	{
		return left+right;
	}
	*/
	Add(1.0, 2);
	Add(1, 2);
	return 0;
}
#endif

#if 0
// ����ģ�壺���Ա�ʵ���������Ͳ�ͬ�Ĳ���
template<class T1,class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1, 2.0);
	return 0;
}
#endif

// ģ�����͵Ķ�̬˳���
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		: _array(new T[capacity])
		, _capacity(capacity)
		, _size(0)
	{}
	void PushBack(const T& data)
	{
		if (_size == _capacity)
		{
			//
		}
		//β��
		_array[_size++] = data;
	}
	void PopBack()
	{
		if (!Empty())
		{
			--_size;
		}
	}
	bool Empty()const
	{
		return _size == 0;
	}
	size_t Size()const
	{
		return _size;
	}
	size_t Capacity()const
	{
		return _capacity;
	}
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	const T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};


int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	cout << array[2] << endl;

	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);

	cout << s1.Size() << endl;
	cout << s1.Capacity() << endl;
	return 0;
}