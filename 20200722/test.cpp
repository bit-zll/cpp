#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//void test(int a)
//{}
//void test(int& a)
//{}
//int main()
//{
//	//test(10);
//	int r = 10;
//	test(r);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	cout << typeid(a).name() << endl;
//	cout << typeid(ra).name() << endl;
//	return 0;
//}

//#include <ctime>
//struct A
//{
//	int array[100000];
//};
//void TestValue(A a)
//{}
//void TestRef(A& a)
//{}
//void TestPtr(A* a)
//{}
//void TestFunc()
//{
//	A a;
//	//��ֵ���ڴ����ڼ���Ҫ����ʵ�ε�һ�ݿ���
//	size_t begin1 = clock();
//	for (int i = 0; i < 10000; i++)
//		TestValue(a);
//	size_t end1 = clock();
//	//�����Ǳ������ڴ����ڼ䲻��Ҫ���п���
//	size_t begin2 = clock();
//	for (int i = 0; i < 10000; i++)
//		TestRef(a);
//	size_t end2 = clock();
//	//��ַ���ڴ����ڼ䲻��Ҫ���ж���Ŀ���
//	size_t begin3 = clock();
//	for (int i = 0; i < 10000; i++)
//		TestPtr(&a);
//	size_t end3 = clock();
//	cout << "��ֵ���ܣ�" << end1 - begin1 << endl;
//	cout << "���������ܣ�" << end2 - begin2 << endl;
//	cout << "��ַ���ܣ�" << end3 - begin3 << endl;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}

//���ÿ��Դﵽ��ָ�����Ƶ�Ч�������磺������ͨ���β����ı��ⲿ��ʵ��
//���⣺ָ���������ʲô����

//�ڵײ�ʵ���ϣ����þ��ǰ���ָ�뷽ʽʵ�ֵ�
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 100;
//
//	int& ra = a;
//	ra = 100;
//	return 0;
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(int* left, int* right)
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	Swap(&a, &b);
//	cout << a << " " << b << endl;
//	return 0;
//}

int main()
{
	int a = 10;
	int& ra = a;
	ra++;//ע�⣺�ڵײ㴦���ϣ����������ra�������ҵ�a

	int b = 20;
	int* p = &b;
	p++;//ָ��ֻ��ָ��һ�������Ŀռ�

	char c = 'a';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;//4 ��32λƽ̨�¡��κ�ָ�붼ռ��4���ֽ�
	cout << sizeof(rc) << endl;//1 ��������ʵ�ʾ���������ʵ�����͵Ĵ�С

	//�ж༶ָ��
	int* p1 = NULL;
	int** p2 = NULL;
	int*** p3 = NULL;

	//û�ж༶����--->û���������
	return 0;
}