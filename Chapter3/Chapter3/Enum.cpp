#include<cstdio>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

enum Gender
{
	MALE, FEMALE,
};

class Student
{
public:
	int student_num;
	char name[20];
	Gender gender;
	Student(const char* _name, int _num, Gender _gender)
	{
		this->student_num = _num;
		strcpy(name, _name);
		this->gender = _gender;

	}
	~Student()
	{

	}
	void printInfo()
	{
		printf("%s �л��� ��ȣ�� %d. ������ %s �̴�. \n",
			this->name, this->student_num, gender == Gender::MALE ? "����" : "����"
		);

	}
};


enum class Month
{
	// DEC �ǹ� �ߺ��� ���� ���� enum class

	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};
class Math
{
public:
	enum Value {
		INC, DEC
	};
};
int main()
{
	//Month m = Month::MAR;
	// ���� ����ȯ ���������
	//int value = (int)m;
}