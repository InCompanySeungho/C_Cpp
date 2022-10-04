#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include<cstdio>
#include<cstring>
#include<cstdlib>

int number_Count = 1;
class Employee
{
public:
	int num = NULL;
	char* name = nullptr;
	int gender; // 0 : ����, 1 : ����
	char* rank = nullptr;

	Employee(char* _name, int _gender, char* _rank)
	{
		this->name = new char[strlen(_name) + 1]; // _name�� ���ڿ� ���� ������(null ���� �����̱� ������ +1 ��������)
		strcpy(this->name, _name);
		this->gender = _gender;
		this->rank = new char[strlen(_rank) + 1];
		strcpy(this->rank, _rank);
		this->num = number_Count;
		number_Count++;
	}
public:
	void printImpormation()
	{
		printf("��ȣ : %d\n", num);
		printf("�̸� : %s\n", name);
		printf("���� : %s\n", gender == 1 ? "����" : "����");
		printf("���� : %s\n", rank);
	}

	~Employee() // �Ҹ��ڴ� �Ķ���� ����
	{
		delete[] name;
		delete[] rank;
	}
};

int getInt(const char* prompt);

// ���� �� �޸��Ҵ� ���� �������
char* getString(const char* prompt);