struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
	char _school[20];

	void SetStudentInfo(char name[], char gender[], int age, char school[]);
	void PrintStudentInfo();
	void Eat();
	void Sleep();
	void Exam();
};