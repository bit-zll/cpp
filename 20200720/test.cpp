#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//ȱʡ���������������庯��ʱ���������Ĳ�������Ĭ��ֵ���ں�������ʱ�����������ʵ��
//����ʵ�Σ�û�д���ʵ����ʹ��Ĭ��ֵ

//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(100);
//	TestFunc();
//	return 0;
//}

//ȱʡ�����ķ���
//1.ȫȱʡ���������в���������Ĭ��ֵ
//2.��ȱʡ���������ֲ�������Ĭ��ֵ

//ȫȱʡ����
//void TestFunc1(int a = 1, int b = 2, int c = 3)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//��ȱʡ����
//void TestFunc2(int a, int b = 2, int c = 3)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//int main()
//{
//	TestFunc1();
//	TestFunc1(10);
//	TestFunc1(10, 20);
//	TestFunc1(10, 20, 30);
//
//	TestFunc2(10);
//	TestFunc2(10, 20);
//	TestFunc2(10, 20, 30);
//	return 0;
//}

//ȱʡ�����������������Ͷ���ʱ��ͬʱ����
//��Ϊ����λ��ͬʱ������һ����Ĭ��ֵ��һ�£�����ʹ����һ��
//�ں�������ʱ������
//��������
//int g_a = 100;
//void TestFunc(int a = g_a);
//��������
//void TestFunc(int a)
//{
//	cout << a << endl;
//}

//����һ��ͨ�����͵ļӷ�����--�����������Ͷ�Ҫ�ܹ�����
//C������;��������һ��������ͬ�ģ������ͬ����ʱ���������ض���
//int AddII(int left, int right)
//{
//	return left + right;
//}
//double AddDD(double left, double right)
//{
//	return left + right;
//}
//char AddCC(char left, char right)
//{
//	return left + right;
//}
//int main()
//{
//	AddII(10, 20);
//	AddDD(10.0, 20.0);
//	AddCC('1','2');
//	return 0;
//}

//C++
//�������أ����������������ͬ���������ֱ�����ͬ�������б���벻ͬ�������������������͡����ʹ���
//�뷵��ֵ�����Ƿ���ͬ�޹أ����������������ֻ����Ϊ����ֵ���Ͳ�ͬ�ǲ��ܹ������أ�
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//char Add(char left, char right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add('1', '2');
//	return 0;
//}

// �����б����Ҫ��ͬ: ����������ͬ  �������Ͳ�ͬ  ���ʹ���ͬ
//void TestFunc()
//{}
//void TestFunc(int a)
//{}
//void TestFunc(double a)
//{}
//void TestFunc(int a, double)
//{}
//void TestFunc(double a, int b)
//{}

//��������ֵ���Ͳ�ͬ�Ͳ��ܹ�������
//��λ�õĺ������þͲ�֪�����ô��з���ֵ�Ļ���û�з���ֵ��TestFunc����--�����������
//int TestFunc(double a, int b)
//{}

// �������ص���ԭ��
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//double Add(int left, double right)
//{
//	return left + right;
//}
//
///*
//�ڱ���������׶Σ���Դ���ʵ�ε����ͽ������ݣ�Ȼ��������ݵĽ��ѡ���Ӧ���͵ĺ������е���
//ע�⣺
//������ɺ�����к��ʵ��������صĺ��������
//����ᷢ����ʽ����ת��---ת��֮���к�����������ã������򱨴�
//*/
//int main()
//{
//	Add(1, 2);      // int, int--->int���͵ļӷ�
//	Add(1.0, 2.0);  // double, double--->double���͵ļӷ�����
//
//	// char,char--->��Add(char,char)�������ź��ú���û�У�
//	// ����Add(int,int)��������char��int֮����Է�����ʽ����ת��
//	Add('1', '2');
//
//	/*
//	double��int֮������໥ת��
//	int,double---->Add(int,double), û�иú���
//
//	��ʱ�ᷢ����ʽ����ת��
//	int,double--->Add(int,int)
//	int,double--->Add(double, double)
//
//	������������--->����
//	*/
//	 //Add(1, 2.0);
//	// �����ʽһ���û��Լ�����ǿת
//	Add(1, (int)2.0);  // --->Add(int,int)
//
//	// �����ʽ�����û�������Ӧ�ĺ�������
//	Add(1, 2.0);
//
//	// Add("hello", "world");  // char*  char* û�к��ʵ�ת�������ã�����ʱ����
//	return 0;
//}

// �������أ�C���Բ�֧�֡�C++֧��----ΪʲôC���Բ�֧�ֺ��������أ�C++�����֧�ֺ������أ�

// ΪʲôC���Բ�֧�ֺ��������أ�--->��Ϊ��C���Ա������Ժ����������ι���ǳ��򵥣�����ֻ���ں�����֮ǰ������_
//int Add(int left, int right);   // C���Ա��������ս��ú��������޸�:_Add
//{
//	return left + right;
//}

//double Add(double left, double right);  // C���Ա��������ս��ú��������޸�:_Add
//{
//	return left + right;
//}

/*
C/C++����ӱ༭�굽�������У�
Ԥ����ͷ�ļ�չ�������滻...
���룺�������ᰴ�ո������Ե��﷨����������Ƿ�����﷨����
��ࣺ�������--->�����ָ���ɶ�Ӧ�Ķ����Ƹ�ʽָ��  mov:1010  push:1011   obj�ļ�
����: ��װ--->�����Ŀ���ļ����ϳ�һ���ļ� + �����ַ����

��������һ����ִ�г���
*/
//int main()
//{
//	/*
//	push 14h
//	push 0Ah
//	call ��������ڵ�ַ_Add
//	*/
//	//Add(10, 20);    // error LNK2019: �޷��������ⲿ���� _Add���÷����ں��� _main �б�����
//	Add(1.0, 2.0);    // error LNK2019: �޷��������ⲿ���� _Add���÷����ں��� _main �б�����
//	return 0;
//}

//int Add(int left, int right)   // C++���������ս��ú��������޸�:?Add@@YAHHH@Z
//{
//	return left + right;
//}

//double Add(double left, double right)  // C++���������ս��ú��������޸�:?Add@@YANNN@Z
//{
//	return left + right;
//}

double Add(int left, double right);

/*
C++�������Ժ������ֵ����ι���
vs
?Add@@YAHHH@Z---->H:int
?Add@@YANNN@Z---->N:double
?Add@@YANHN@Z
?��ͷ ֮����Ǻ���������Add  ��һ��@���ű�ʾ�������ֽ���  @YA֮�����������ֵ�Լ���������  @Z��ʾ�����б����

C++�������ڶԺ�����������ʱ�����ս�����������Ϣ���뵽������ȥ��
*/
int main()
{
	//Add(1, 2);   // �޷��������ⲿ���� "int __cdecl Add(int,int)" (?Add@@YAHHH@Z)
	//Add(1.0, 2.0); // �޷��������ⲿ���� "double __cdecl Add(double,double)" (?Add@@YANNN@Z)
	Add(1, 2.0);   // �޷��������ⲿ���� "double __cdecl Add(int,double)" (?Add@@YANHN@Z)
	return 0;
}