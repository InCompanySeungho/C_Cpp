#include<cstdio>
#include<cstring>
#pragma warning (disable:4996)

/*
class Animal
{
public:
	int legs = NULL;
	char name[50] = {NULL ,};
	Animal(int _legs, const char* _name) // �⺻������
	{
		this->legs = _legs;
		strcpy(this->name, _name);
	}
	void print_AnimalInfo()
	{
		printf("�ٸ��� ���� : %d\n", legs);
		printf("������ �̸� : %s\n", name);
	}
};
class Person : public Animal
{
public:
	char regist_num[30];

	Person(const char* _regist_num) : Animal(2, "���")
	{
		strcpy(this->regist_num, _regist_num);
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal(4, "��")
	{
		printf("Dog ������ ����");
	}
};

int main()
{
	Animal* a;

	Person* p = new Person("1234-5678"); // Person() : �����ڸ� ȣ���Ѵ� / Person : �����ڸ� ȣ������ �ʴ´�.
	p->print_AnimalInfo();

	Dog* d = new Dog;
	d->print_AnimalInfo();


	p = (Person*)a;
	delete p;
}
*/


class Weapon
{
private :
	int damage = NULL;
	int range = NULL;
	int price = NULL;
public:
	Weapon(int _damage,int _range, int _price )
	{
		this->damage = _damage;
		this->range = _range;
		this->price = _price;
	}

	void printInfo()
	{
		printf("���ݷ� : %d\n", this->damage);
		printf("�����Ÿ� : %d\n", this->range);
		printf("���� : %d\n", this->price);
	}
};

class ShortType : public Weapon
{
public:
	ShortType() : Weapon(10, 5, 500)
	{
		printf("�� �ҵ� Ȱ��ȭ\n");
	}
};
class LongType : public Weapon
{
public:
	LongType() : Weapon(20, 10, 2000)
	{
		printf("�� �ҵ� Ȱ��ȭ\n");

	}
};
class Hammer : public Weapon
{
public:
	Hammer() : Weapon(30, 7, 3000)
	{
		printf("�ظ� Ȱ��ȭ\n");

	}
};
int main()
{
	ShortType* st = new ShortType;
	st->printInfo();

	LongType* lt = new LongType;	
	lt->printInfo();

	Hammer* hm = new Hammer;
	hm->printInfo();
}