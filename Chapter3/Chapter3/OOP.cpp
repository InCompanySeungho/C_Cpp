#include<iostream>
#include<cstdio>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
struct Person
{
	// �Ӽ�
	int age;
	float salary;
	int gender;
	char name[100];

	// �ൿ
	void work();
	void off();

	// �Ӽ��� �ൿ�� ������ �� : �߻�ȭ(Abstraction)
};
struct ProtossUnit
{
	int shieldAmount = 0;
	int shieldRegen = 0;
	int shieldArmmor = 0;
	int hp = 0;
};

// �������� ���� ��, �������� ������ ���� (�ڽ�Ŭ����)��(�θ�Ŭ����) �̷� ȭ��ǥ ������ �̿��Ѵ�. 
struct Zealot : ProtossUnit
{
	Zealot()
	{
		hp = 80;
		shieldAmount = 60;
	}
};


struct Dragon : ProtossUnit
{
	Dragon()
	{
		hp = 100;
		shieldAmount = 80;
	}
};

class Student
{
public:
	int student_num;
	char* name;
	int gender;


	// �����ڸ� ����� �������δ� Ŭ������ Ȱ���� �� ���Եȴ�.
	Student(int student_num, const char* n, int g) 
	{
		this->student_num = student_num; // this = Ŭ������ ������ �ǹ��Ѵ�.
		// �ڱ��ڽ��� �ν��Ͻ�(������Ÿ��)�� ������ �� �ִ�.
		name = new char[strlen(n) + 1]; // strlen : ���ڿ��� ���̸� ��Ÿ����.(null���� ����)
		// null���ڸ� ������ ���̸� �������� ���ؼ� + 1
		strcpy(name, n);
		gender = g;

	}

	~Student() // �Ҹ��� : �Ķ���͸� ���� �ʴ´�
	{
		printf("%s �� �Ҹ��� ȣ��", name);
		delete[] name;
		
	}
};

int main()
{
	//Zealot* zealot;
	//ProtossUnit* protossUnit;

	//zealot = (Zealot*)protossUnit; //�������� ����ȯ ���������
	//protossUnit = zealot; //


	Student s = Student(1234, "ȫ�浿", 0); // �Լ��� ������ �Ǹ� ������ �������. ( �Ҹ��� �ڵ�ȣ�� )
	//s.student_num = 1234;
	//strcpy(s.name, "ȫ�浿");
	//s.gender = 0;

	Student* ps = new Student(3456,"����ȫ�浿", 1);
	// new Ű���带 �̿��Ͽ� Ŭ������ �Ҵ��ϸ�, �Լ��� ���� ���� Heap ������ ����ȴ�. �Լ��� �����ֱ�(����������Ŭ)�� ������� �����ȴ�.
	//ps->student_num = 3456;
	//strcpy(ps->name, "����ȫ�浿");
	//ps->gender = 1;

	delete ps; // new Ű���带 ����Ͽ� Ŭ���� �ν��Ͻ��� ������ٸ�, delete Ű���带 ����ؼ� �ν��Ͻ��� ���� ���� Heap �޸𸮿��� ��������� �Ѵ�.
	return 0;
}

