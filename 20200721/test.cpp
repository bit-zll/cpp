#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//ȫȱʡ�ĺ�����ͬ�����޲κ���ֻ�ܴ���һ��
//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc()
//{
//	cout << "void TestFunc()" << endl;
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}

//void Swap(int left, int right)
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
//	cout << a << " " << b << endl;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	Swap(&a, &b);
//	cout << a << " " << b << endl;
//	return 0;
//}
//��ֵ�ʹ�ַ��ʲô������ʲô��ȱ�㣿
//1.��ֵ���βν������ܵ�����ʵ�ε�һ����ʱ������
//        �ں�����������βν��иı䣬����Ӱ���ⲿʵ��
//2.��ַ���βν������õ���ʵ�εĵ�ַ��ͨ�����βν������õ�ʵ�Σ�
//        ���βν����ý����޸ģ�ʵ���޸ĵ����ⲿ��ʵ�Σ�����ͨ���β����ı��ⲿ��ʵ��
//3.��ַ�ȴ�ֵ��Ч�ʸߣ���ֵ��Ҫ����ʵ�α����һ����ʱ���������ʵ�����ͱȽϴ�
//���������ĸ����ͱȽϴ󡣴�ַ��Ҫ����ʵ�ε�ַ��һ�ݿ������β�ֻռ4���ֽڣ�32λ��
//��ַ����Ч�ʸߣ����ҽ�ʡ�ռ�
//4.��ֵ�ȴ�ַ����ȫ--ָ�����Ҫ�п�
//5.��ֵ�ȴ�ַ����Ŀɶ��Ը�

//��ʲô��ȱ�㣿
//��ֵ��
//�ŵ㣺1.����ɶ��Ըߡ��ϰ�ȫ2.����ͨ���βθı��ⲿ��ʵ�Σ���ʱ���βθ���Ҳ����Ӱ���ⲿʵ��
//ȱ�㣺1.����Ч�ʵͣ��˷ѿռ䣨���ݵ���ʵ�εĸ�����2.�����Ҫͨ���βθı��ⲿʵ��ʱ��������
//����ַ��
//�ŵ㣺1.����Ч�ʸߣ���ʡ�ռ䣨���ݵ���ʵ�εĵ�ַ--32λƽ̨4�ֽڣ�2.����ͨ���βθı��ⲿ��ʵ��
//ȱ�㣺1.��ȫ�Եͣ��ɶ��Ե�2.�������ͨ���βθı��ⲿʵ��ʱ���ܻ����������

//void TestRef()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	cout << a << endl;
//	cout << &a << " " << &ra << endl;
//}
//int main()
//{
//	TestRef();
//	return 0;
//}
//���ã����Դﵽָ�����Ƶ�Ч��
//�����Ҫһ��ָ�룬����ֱ��������������
//�����Ҫ����ָ�룬����ֱ��ʹ��һ��ָ�������������
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int& rb = a;
//	int& rc = a;
//	cout << &a << " " << &ra << " " << &rb << " " << &rc << endl;
//	return 0;
//}

//���⣺���ñ������������ڳ�����ʵ����������ڳ���ʵ��

//������-->const���͵�����
//int main()
//{
//	const int a = 10;//a���ܱ��޸�
//	//int& ra = a;
//	const int& ra = a;
//	cout << &a << " " << &ra << endl;
//
//	const int& rb = 100;
//
//	double d = 12.34;
//	const int& rd = d;
//	d = 23.34;
//	cout << rd << endl;//rd����ı䣬��Ϊrd�ĵ�ַ��d�ĵ�ַ��ͬ
//	return 0;
//}

//���õ�Ӧ�ó���
//1.���ֱ�Ӹ�ĳ��ʵ��ȡ����---Ϊ��д�����
//2.��Ϊ�������βΣ����Դﵽָ�����Ƶ�Ч��---������ͨ���βθı��ⲿ��ʵ��
//3.��������Ϊ�����ķ���ֵ
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}
int main()
{
	int& sum = Add(1, 2);
	cout << sum << endl;
    Add(3, 4);//sumҲ��Ϊ7
	return 0;
}