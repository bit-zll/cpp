#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class Test
//{
//public:
//	Test(int t)
//		: _t(t)
//	{}
//	Test& operator=(const Test& t)
//	{
//		if (this != &t)
//		{
//			_t = t._t;
//		}
//		return *this;
//	}
//	int _t;
//};
//
////��ֵ��������ر���д����ĳ�Ա����
////Test& operator= (Test& t)
////{
////    return t;
////}
////ע�⣺����˵���е���������ض�Ҫд����ĳ�Ա����
////���磺���ص���������
//
//int main()
//{
//	Test t1(10);
//	Test t2(20);
//
//	t1 = t2;
//	return 0;
//}

class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " "<< _t <<endl;
	}
	~Test()
	{
		cout << "~Test():" << this <<" " << _t << endl;
	}
	int _t;
};
Test t1(10);

int main()
{
	Test t2(20);
	Test t3(30);
	static Test t4(40);

	return 0;
}

//1.ȫ�ֶ��������������������������Ľ�����������
//2.��̬�ֲ����󣬺�����һ�α�����ʱ����������ÿ�ε����򲻻����������������Ľ�����������
//3.�������оֲ����󣺰��溯�������ж����������ź����Ľ��������١�
//�ֲ�����洢��ջ�ϣ�ջ�ϵĶ��󴴽������ٵĹ������ջ�����ԣ����ȴ����ĺ����١�