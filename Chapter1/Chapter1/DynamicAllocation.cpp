// �޸� ���� �Ҵ�� �迭
#include "Header.h"

struct Marine
{
	int hp;
	int mp;
	char name[20];
};

Marine* foo() // Marine �̶�� ����ü ������Ÿ��
{
	Marine m;
	m.hp = 100;
	m.mp = 50;
	strcpy(m.name, "Jim Raynor"); // �����̶�� ����ü�� �̸� �Ҵ�
	return &m; // ���� �ּҰ��� ����
}

Marine* Allocfoo() // �޸� �����Ҵ� �� ����ü ������Ÿ��
{

	Marine* m = (Marine*) malloc(sizeof(Marine));
	m->hp = 100; // -> ������ ������ : ���� �Ҵ�� ����ü�� ������ ������ '��� ����' �� �����ϱ� ���Ͽ� ����Ѵ�.
	m->mp = 50;
	strcpy(m->name, "Jim Raynor");
	return m; // ��ȯ�� �ּҰ��� �������� �ʴ´�?
}
int main()
{
	/*
	int myArray[100]; 
	// �迭 �ε����� ����־� ���� ��������  [] ���ȣ��
	// �ش� �ּҰ����� �� ��° ������ ���� ���������� ��� �ǹ̸� ������ �ִ�.
	int* p_myArray = myArray;
	const char* myString = "HelloWorld"; // �޸� �����Ҵ�
	// �迭�̳� �����͸� ��ǻ���� �޸� ��(��) ������ �ڸ���Ű�°�.
	// �Լ��� �����ֱ�� �����ϰ� ���α׷� ������� ��Ƴ��� �޸� �����̴�
	p_myArray[0] = 100;
	p_myArray[1] = 200;
	p_myArray[2] = 300;
	printf("%d\n", myArray[0]);
	printf("%d\n", myArray[1]);
	printf("%d\n", myArray[2]);
	*/


	Marine* m = foo(); // Marine �� ����ü Ÿ���� �����Ա⿡, 
	Marine* allocm = Allocfoo();
	//printf("%s", (*m).name); // foo() �� �Ҵ簪�� m�� ���� �ִ´�
	printf("%s", (*allocm).name);
	free(allocm);

	// free() : cstdlib �� ���ԵǾ��ִ�
	// �����Ҵ�� ����, �迭���� �������ִ� �Լ�

	// �̸� ��� �ȵǴ� ���� : �Լ� ������ ������, �Լ� ������ �������� ���� �ı��ȴ�.

	// �����Ͱ��� ������ ���� �޸𸮸� ���� �Ҵ� �ؾ��Ѵ� : malloc()
	// Type v = (Type*)malloc(sizeof(Type));
	return 0;
}