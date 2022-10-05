#include<stdio.h>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
// �������̵� ���� : 
// �θ�Ŭ������ �Լ��� ���Ǹ� �ڽ�Ŭ�������� ���� ����� ��
// �Լ���, �Ķ���ͱ��� ��� ���� �Լ��� ������ ��
class Animal
{
public:
	int legs;
	char* name;

	Animal(int legs, const char* name)
	{
		this->legs = legs;
		name = new char[strlen(name) + 1];
		 strcpy(this->name, name);
	}
	// virtual : �������̵��� ��, �θ�Ŭ������ �Լ�����
	// Ű���带 �߰��ϸ� ���������� �������̵�� �Լ��� ã�ư��� �����Ѵ�.
	// virtual Ű���带 �߰���
	virtual void printInfo() 
	{
		printf("�ٸ� : %d, �̸� : %s\n", legs, name);
	}
	// �Ҹ��ڿ����� virtual Ű���带 ���� ������,
	// ��ӹ��� Ŭ������ ��� ���� Ÿ�Կ� �´� �Ҹ��ڸ� ȣ���ϰ� �ȴ�.
	// -> �޸� ������ �̾���
	virtual ~Animal()
	{
		printf("Animal �Ҹ��� ȣ��\n");
		delete[] name;
	}
};

class Human : public Animal
{

	char regist_num[40];
public:
	Human(const char* _resist_num) : Animal(2, "���")
	{
		strcpy(this->regist_num, _resist_num);
	}
	void printInfo() 
	{
		printf("�̸� : %s, �ֹε�Ϲ�ȣ : %s\n", name, this->regist_num);
	}

	~Human()
	{
		printf("Human �Ҹ��� ȣ��\n");
	}
};

// 3���� ��� Matrix ����.
// Matrix�� ���� Ŭ���� �ν��Ͻ��� ������� ���ϴ� ������ �����ε� �Լ� ����


class Matrix
{
public:
	float x;
	float y;
	float z;
	Matrix(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

	void printInfo()
	{
		printf("x : %.2f, y : %.2f, z : %.2f\n", x, y, z);
	}
};

Matrix operator+(Matrix & _mat1, Matrix& _mat2)
{
	return Matrix(_mat1.x + _mat2.x, _mat1.y + _mat2.y, _mat1.z + _mat2.z);
}
int main()
{
	Human* human = new Human("1234-5678");
	Animal* animal = new Animal(2, "��");

	animal = (Animal*)human; // human�� 
	animal->printInfo();
	delete animal;
	// Matrix
	/*
	Matrix mat1 = Matrix(4, 4, 4);
	Matrix mat2 = Matrix(10, 12, 14);

	Matrix sumMat = mat1 + mat2;
	sumMat.printInfo();*/
	return 0;
}