#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#if 0
#include <windows.h>

int main()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf)
	{
		size_t errNo = GetLastError();
		cout << "���ļ�ʧ��" << endl;
		return -1;
	}

	// �Ը��ļ����в���

	fclose(pf);

	return 0;
}
#endif



#if 0
// setjmp��longjmp
// �����ں���֮ǰ��������ת
// ��������ִ�����������������̷��뿪��
// ��longjmp��������ִ��֮ǰ������Ҫ��������ת��λ��


// ��¼����һЩ�Ĵ�������Ϣ��Ҫ��ת����λ�õļĴ�����Ϣ
jmp_buf buff;

void TestFunc1()
{
	FILE* pf = fopen("1.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 1);
	}

	// ���ļ����в���

	fclose(pf);
}

void TestFunc2()
{
	char* p = (char*)malloc(0xffffffff);
	if (nullptr == p)
	{
		longjmp(buff, 2);
	}

	// ��������
	free(p);
}


int main()
{
	// setjmp�������ڵ�һ�ε��õ�ʱ��᷵��0
	// Ȼ�󽫵�ǰ�Ĵ�����״̬��¼��buff�У����оͰ����˳���Ҫ
	// ִ�е���һ��ָ��ĵ�ַ
	int istate = setjmp(buff);
	if (0 == istate)
	{
		TestFunc1();
		TestFunc2();
	}
	else
	{
		// ˵��������һЩ����
		switch (istate)
		{
		case 1:
			cout << "TestFunc1(): ���ļ�ʧ��" << endl;
			break;
		case 2:
			cout << "TestFunc2():malloc����ռ�ʧ��" << endl;
			break;
		default:
			cout << "δ֪����" << endl;
		}
	}


	return 0;
}
#endif


#if 0

// �쳣�������ض��������»ᷢ��
// ����ÿ�ζ��ᷢ��
void TestFunc1()
{
	FILE* pf = fopen("1.txt", "rb");
	if (nullptr == pf)
	{
		throw '1';
	}

	// ���ļ����в���

	fclose(pf);
}

void TestFunc2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		throw 2;
	}

	// ��������
	free(p);
}

int main()
{
	// TestFunc2();
	try
	{
		// ע�⣺�����п��ܻ��ʳ��쳣�ĺ����������try�Ŀ���
		TestFunc1();
		TestFunc2();
	}
	catch (int err)  // ����throw�׳������͵��쳣�Ĵ���
	{
		cout << err << endl;
	}
	catch (char err)    // ����׳��쳣�����ͱȽ϶࣬ÿ�����͵��쳣����Ҫ����
	{
		cout << err << endl;
	}

	// ......
	cout << "hello world" << endl;
	return 0;
}
#endif



#if 0
void TestFunc2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		throw 2;   // �����ڴ�ʧ��
	}

	// ��������
	free(p);
}


void TestFunc1()
{
	int* p = new int[10];
	FILE* pf = fopen("1.txt", "w");
	if (nullptr == pf)
	{
		throw '1';
	}

	// ���ļ����в���

	try
	{
		TestFunc2();
	}
	catch (...)   // ... ���ܲ���ʽ
	{
		// ����TestFunc2���׳��쳣��Ŀ�ģ�����Ϊ���ͷ���Դ
		// ������Դ��û�л����ͷ������Դй©
		// ע�⣺TestFunc2�е��쳣����û�д��������Ҫ��TestFunc2�е��쳣����������
		delete[] p;
		fclose(pf);
		// return;
		throw;
	}


	// ��������
	delete[] p;
	fclose(pf);
}


int main()
{
	try
	{
		TestFunc1();
	}
	catch (int err)
	{
		cout << err << endl;
	}

	return 0;
}
#endif


#if 0
class T
{
public:
	T()
	{
		cout << "T():" << this << endl;
	}

	T(const T&)
	{
		cout << "T(T T&):" << this << endl;
	}

	~T()
	{
		cout << "~T()" << this << endl;
	}
};

void Test()
{
	int a = 10;
	cout << &a << endl;
	//throw a;   // �׳��쳣֮��Ҳ�൱�ں���������

	T t;
	throw t;
}


int main()
{
	int* p = nullptr;
	try
	{
		Test();
	}
	catch (T& t)
	{
		// ra����Test���׳�����ʱ����a�ı���
		cout << "��������" << endl;
	}

	return 0;
}
#endif



#if 0
int main()
{

	char* p = nullptr;

	try
	{
		p = new char[0x7fffffff];
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return 0;
	}


	delete[] p;

	return 0;
}
#endif


#if 0
// �ú������Ҫ���쳣��ֻ���׳�int���͵��쳣
void Test1()throw(int)
{
	throw 1.0;
}

// һ�������׳��쳣��  
void Test2()throw()
{}



int main()
{
	return 0;
}
#endif


#include <string>


// һ�㶼���Զ����Լ����쳣��ϵ�ṹ
class Exception
{
public:
	Exception(size_t errno, const string& info)
		: _errno(errno)
		, _info(info)
	{}

	virtual void What() = 0;

protected:
	string _info;
	size_t _errno;
};



class DBException : public Exception
{
public:
	DBException(size_t errno, const string& info)
		: Exception(errno, info)
	{}

	virtual void What()
	{
		cout << "���ݿ����" << endl;
	}
};


int main()
{
	return 0;
}
