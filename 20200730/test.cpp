#define _CRT_SECURE_NO_WARNINGS 1
//#include "Student.h"
#include <string.h>
#include <iostream>
using namespace std;


//void Student::SetStudentInfo(char name[], char gender[], int age, char school[])
//{
//	strcpy(_name, name);
//	strcpy(_gender, gender);
//	_age = age;
//	strcpy(_school, school);
//}
//void Student::PrintStudentInfo()
//{
//	cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
//}
//void Student::Eat()
//{
//	cout << "�Է�" << endl;
//}
//void Student::Sleep()
//{
//	cout << "˯��" << endl;
//}
//void Student::Exam()
//{
//	cout << "����" << endl;
//}
//int main()
//{
//	Student s1, s2;
//	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
//	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
//	
//	s1.PrintStudentInfo();
//	s2.PrintStudentInfo();
//}

//class Student
//{
////protected:
//public:
//	char _name[20];
//	char _gender[3];
//	int _age;
//	char _school[20];
//public:
//	void SetStudentInfo(char name[], char gender[], int age, char school[])
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//		strcpy(_school, school);
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
//	}
//	void Eat()
//	{
//		cout << "�Է�" << endl;
//	}
//	void Sleep()
//	{
//		cout << "˯��" << endl;
//	}
//	void Exam()
//	{
//		cout << "����" << endl;
//	}
//};
//int main()
//{
//	Student s1, s2;
//    s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
//	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
//
//	s1.PrintStudentInfo();
//	s2.PrintStudentInfo();
//
//	s1.Eat();
//	s1.Sleep();
//	s1.Exam();
//
//	
//	return 0;
//}

// C++��4�������򣺺������еľֲ�������ȫ�������������ռ䡢��

// ���еĳ�Ա������ֻ�������Ա������ʹ�ã���Ա�����൱�������Ա������ȫ�ֱ���
//class Test
//{
//public:
//	void SetTest(int a)
//	{
//		_a = a;
//		cout << &_a << endl;
//	}
//	void PrintTest()
//	{
//		cout << _a << endl;
//		cout << &_a << endl;
//	}
//private:
//	int _a;// �ó�Ա�������ȿ�����SetTest������ʹ�ã�Ҳ������PrintTest������ʹ��
//	       // ��ˣ���Ա�����Ϳ��Կ��������Ա������ȫ�ֱ���
//};
//
//// ע�⣺��Ա�����Ϳ��Կ��������Ա������ȫ�ֱ���---���Ǻ�������ȫ�ֱ�������������
////      ȫ����ʹ��֮ǰ������Ҫ���ж���
//
//int g_a = 10;
//void TestFunc()
//{
//	cout << g_a << endl;
//}
//
//int main()
//{
//	Test t;
//	t.SetTest(10);
//	t.PrintTest();
//
//	cout << g_a << endl;
//	return 0;
//}

//class Student
//{
//public:
//	// ���ԣ���������ѧ���Ļ�����Ϣ��
//	char _name[20];
//	char _gender[3];
//	int  _age;
//	char _school[20];
//
//public:
//	void SetStudentInfo(char name[], char gender[], int age, char school[])
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//		strcpy(_school, school);
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
//	}
//
//	// ��Ϊ��ѧ������ɶ
//	// �Է���˯�����ϿΡ�д��ҵ�����ԡ����---����һ�㶼��ͨ���������ֵ�
//	void Eat()
//	{
//		cout << "�ú÷��Գ�����" << endl;
//	}
//
//	void Sleep()
//	{
//		cout << "ZZZ~~~" << endl;
//	}
//
//	void Exam()
//	{
//		cout << "����" << endl;
//	}
//};
//
//int main()
//{
//	/*
//	����������ʧ�ܣ���ΪStudent��һ��ѧ���������
//	ѧ��Ⱥ����𣺾�������---����û������һ˵
//	ͨ��ѧ������ ���������ѧ��ʵ��(ѧ��������������һ��ѧ��)����һ��������ѧ���������֡��Ա�����
//	*/
//	//Student._age = 10;
//
//	Student s;  // s������ʵ�����Ľ����s����һ��������ѧ��
//	s._age = 10;
//
//	return 0;
//}

class Student
{
public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public:
	// ���ԣ���������ѧ���Ļ�����Ϣ��
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;

	// Ҫ���Student������ж������Ҫ֪�������ж���������Щ��Ա
	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
	s3.SetStudentInfo("ǿ��", "��", 28, "ɭ�ִ�ѧ");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	cout << sizeof(s1) << endl;//28 ע���ڴ���� 20+3+1+4=28
	return 0;
}