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
		cout << "打开文件失败" << endl;
		return -1;
	}

	// 对该文件进行操作

	fclose(pf);

	return 0;
}
#endif



#if 0
// setjmp和longjmp
// 可以在函数之前来进行跳转
// 将正常的执行流程与错误处理的流程分离开了
// 在longjmp（）函数执行之前，必须要设置其跳转的位置


// 记录的是一些寄存器的信息：要跳转到的位置的寄存器信息
jmp_buf buff;

void TestFunc1()
{
	FILE* pf = fopen("1.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 1);
	}

	// 对文件进行操作

	fclose(pf);
}

void TestFunc2()
{
	char* p = (char*)malloc(0xffffffff);
	if (nullptr == p)
	{
		longjmp(buff, 2);
	}

	// 正常操作
	free(p);
}


int main()
{
	// setjmp方法：在第一次调用的时候会返回0
	// 然后将当前寄存器的状态记录到buff中，其中就包含了程序将要
	// 执行的下一条指令的地址
	int istate = setjmp(buff);
	if (0 == istate)
	{
		TestFunc1();
		TestFunc2();
	}
	else
	{
		// 说明程序发生一些错误
		switch (istate)
		{
		case 1:
			cout << "TestFunc1(): 打开文件失败" << endl;
			break;
		case 2:
			cout << "TestFunc2():malloc申请空间失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
		}
	}


	return 0;
}
#endif


#if 0

// 异常：是在特定的条件下会发生
// 不是每次都会发生
void TestFunc1()
{
	FILE* pf = fopen("1.txt", "rb");
	if (nullptr == pf)
	{
		throw '1';
	}

	// 对文件进行操作

	fclose(pf);
}

void TestFunc2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		throw 2;
	}

	// 正常操作
	free(p);
}

int main()
{
	// TestFunc2();
	try
	{
		// 注意：对于有可能会剖出异常的函数必须放在try的块中
		TestFunc1();
		TestFunc2();
	}
	catch (int err)  // 捕获：throw抛出的类型的异常的错误
	{
		cout << err << endl;
	}
	catch (char err)    // 如果抛出异常的类型比较多，每种类型的异常都需要捕获
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
		throw 2;   // 申请内存失败
	}

	// 正常操作
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

	// 对文件进行操作

	try
	{
		TestFunc2();
	}
	catch (...)   // ... 万能捕获方式
	{
		// 捕获TestFunc2中抛出异常的目的：就是为了释放资源
		// 否则资源就没有机会释放造成资源泄漏
		// 注意：TestFunc2中的异常根本没有处理，因此需要将TestFunc2中的异常继续往出抛
		delete[] p;
		fclose(pf);
		// return;
		throw;
	}


	// 其他操作
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
	//throw a;   // 抛出异常之后，也相当于函数结束了

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
		// ra不是Test中抛出的临时变量a的别名
		cout << "发生错误" << endl;
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
// 该函数如果要抛异常，只能抛出int类型的异常
void Test1()throw(int)
{
	throw 1.0;
}

// 一定不会抛出异常的  
void Test2()throw()
{}



int main()
{
	return 0;
}
#endif


#include <string>


// 一般都会自定义自己的异常体系结构
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
		cout << "数据库错误" << endl;
	}
};


int main()
{
	return 0;
}
