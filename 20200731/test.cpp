#define _CRT_SECURE_NO_WARNINGS 1
#include "Student.h"
#include <iostream>
#include <string.h>
using namespace std;

//class A1
//{
//public:
//	void f1(){}
//private:
//	int _a;
//	char _b;
//};
//class A2
//{
//public:
//	void f2(){}
//};
//class A3
//{};
//struct A
//{
//	int a;
//	char b;
//	double c;
//	char d;
//};
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	A3 a1, a2, a3;
//	cout << &a1 << " " << &a2 << " " << &a3 << endl;
//
//	cout << offsetof(A, b) << endl;
//	cout << offsetof(A, c) << endl;
//	return 0;
//}

// ע�⣺��C++�У��۾������Ĳ�һ���������----���������ڴ����͵͵�����޸�
// ÿ����"��Ա����"����һ��Ĭ�ϵĲ������ò���ʱʱ�̿�ָ����øó�Ա�����Ķ��󣬽��ò�����Ϊthisָ��
// ע�⣺�����ص�thisָ���Ǳ������ڱ�������ڼ��Զ����ϵ�,����û�����Ҫ��ӣ�Ҳ����Ҫ����
//class Student
//{
//public:
//	void SetStudentInfo(/*Student const this*/char name[], char gender[], int age);
//	//{
//	//	//this=nullptr;   thisָ��ָ�����޸�
//	//	strcpy(this->_name, name);
//	//	strcpy(this->_gender, gender);
//	//	this->_age = age;
//	//}
//	//void PrintStudentInfo(/*Student const this*/)
//	//{
//	//	cout << this->_name << "-" << this->_gender << "-" << this->age << endl;
//	//}
//public:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//int main()
//{
//	Student s1, s2, s3;
//
//	// thisָ��û�а����ڶ����У���Ӱ�����Ĵ�С�����Ǳ���������Ա�������ӵ�һ���������ֲ�ͬ�����ָ�����
//	cout << sizeof(s1) << endl;
//
//	//thisָ��Ĵ��ݷ�ʽ��
//	// 1. �ò������б��������ݵ�
//	// 2. һ������ò�����ͨ��ecx�Ĵ��������ݵ�
//	// ע�⣺һ������³�Ա�������Ǳ�this_call����Լ�����Σ�����this_call����Լ�����εĳ�Ա����
//	//      thisָ����ͨ��ecx�Ĵ�������, ��_cdecl����Լ�����εĳ�Ա������this��ͨ������ѹջ�ķ�ʽ����
//	return 0;
//}

// ��C�����У����Ǵ�����ôд������������ô�����������Դ�������κ��޸�--�㿴���ľ��Ǳ�����ִ�е�

//#include <stdio.h>
//#include <string.h>
//typedef struct Student
//{
//	char name[20];
//	char gender[3];
//	int age;
//}Student;
//
//void SetStudentInfo(Student* this, char name[], char gender[], int age)
//{
//	strcpy(this->name, name);
//	strcpy(this->gender, gender);
//	this->age = age;
//}
//void PrintStudentInfo(Student* this)
//{
//	printf("%s %s %d", this->name, this->gender, this->age);
//}
//int main()
//{
//	Student s1, s2, s3;
//	SetStudentInfo(&s1, "�ܴ�","��", 5);
//	SetStudentInfo(&s2, "�ܶ�","ĸ", 4);
//	SetStudentInfo(&s3, "ǿ��", "��", 28);
//
//	PrintStudentInfo(&s1);
//	PrintStudentInfo(&s2);
//	PrintStudentInfo(&s3);
//	return 0;
//}

void Student::SetStudentInfo(char name[], char gender[], int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Student::PrintStudentInfo()
{
	cout << _name << "-" << _gender << "-" << _age << endl;
}

int main()
{
	Student s1, s2;
	s1.SetStudentInfo("�Ű�", "��", 25);
	s2.SetStudentInfo("����", "Ů", 24);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	return 0;
}