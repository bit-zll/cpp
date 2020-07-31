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

// 注意：在C++中，眼睛看到的不一定就是真的----编译器对于代码会偷偷进行修改
// 每个类"成员函数"都有一个默认的参数，该参数时时刻刻指向调用该成员函数的对象，将该参数称为this指针
// 注意：该隐藏的this指针是编译器在编译类的期间自动加上的,因此用户不需要添加，也不需要传递
//class Student
//{
//public:
//	void SetStudentInfo(/*Student const this*/char name[], char gender[], int age);
//	//{
//	//	//this=nullptr;   this指针指向不能修改
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
//	// this指针没有包含在对象中，不影响对象的大小，它是编译器给成员函数增加的一个用来区分不同对象的指针参数
//	cout << sizeof(s1) << endl;
//
//	//this指针的传递方式：
//	// 1. 该参数是有编译器传递的
//	// 2. 一般情况该参数是通过ecx寄存器来传递的
//	// 注意：一般情况下成员函数都是被this_call调用约定修饰，即被this_call调用约定修饰的成员函数
//	//      this指针是通过ecx寄存器传递, 被_cdecl调用约定修饰的成员函数，this是通过参数压栈的方式传递
//	return 0;
//}

// 在C语言中，我们代码怎么写，编译器就怎么做，几乎不对代码进行任何修改--你看到的就是编译器执行的

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
//	SetStudentInfo(&s1, "熊大","公", 5);
//	SetStudentInfo(&s2, "熊二","母", 4);
//	SetStudentInfo(&s3, "强哥", "男", 28);
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
	s1.SetStudentInfo("张安", "男", 25);
	s2.SetStudentInfo("李四", "女", 24);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	return 0;
}