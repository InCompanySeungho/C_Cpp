#include "Header.h"

struct Marine
{
	int hp = 40;
	int atk = 6;
};

void foo(int* a, int count) // �Ķ������ ������
{
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", a[i]);
	}
}

void goo(const char* str) // �Ķ������ ������
{
	// �ϵ��ڵ��� string���� "value" �� const. ��������� �޾ƿ;��Ѵ�.
	printf("%s", str);
}

int main()
{
#pragma region  ���� �ʱ�ȭ
	//int* pointer = 0;
	int* pointer = nullptr; // c, c++ ������ ǥ�� = nullptr

	pointer = (int*)malloc(sizeof(int));
	//printf("%d,", pointer);

	free(pointer);
	pointer = nullptr;
#pragma endregion


#pragma region  �迭 �ʱ�ȭ
	// Type v[10] ={0.};
	// Type v[10] = {nullptr,};
	int myArray[10] = {0,};

	for (int i = 0; i < 10; i++)
	{
		//printf("myArray[%d] = %d\n", i, myArray[i]);
	}

#pragma endregion

#pragma region ����ü �ʱ�ȭ


	//Marine* marine = nullptr;
	//Marine* marine_arr[40] = {nullptr,  }; // �������� �迭�� null �����ͷ� �ʱ�ȭ

	Marine* marine[40] = { nullptr, };
	for (int i = 0; i < 40; i++)
	{
		marine[i] = (Marine*)malloc(sizeof(Marine));
		marine[i]->hp = 40;
		marine[i]->atk = 7;
	
}
	for (int i = 0; i < 40; i++)
	{
		//printf(" marine[%d].atk = %d\n", i,marine[i]->atk);

	}

#pragma endregion

#pragma region �������� ������
	// ���������Ϳ���
	// �⺻�� ������ Ÿ���̶�� : 2���� �迭�� ���ɼ� ����
	// ����ü Ÿ���̶�� : �������� �迭�� ���ɼ� ����

	// int** v // int�� 2���� �����迭�� ���ɼ� ����
	// Type** v // Type* �� 1���� �����迭�� ���ɼ� ����

	Marine* pMarine[20]; // �Ʒ��� ���������Ϳ� ���� �ǹ�
	Marine** ppMarine; // �ּҰ��� �ּҰ�
	ppMarine = (Marine**)malloc(sizeof(Marine*) * 20); // �����ʹ� �׻� 4byte
	// malloc �ּ��� �������� �� ����(��������ʴ�) �� ������ ������ش�.
	for (int i = 0; i < 20; i++)
	{
		ppMarine[i] = (Marine*)malloc(sizeof(Marine));
		ppMarine[i]->atk = 8;
	}

	for (int i = 0; i < 20; i++)
	{
		//printf("marine[%d]->atk = %d\n", i, ppMarine[i]->atk);
	}

	free(pMarine);
	free(ppMarine);
#pragma endregion

#pragma region  �Ķ������ ������
	// ������ �ּҰ��� �ޱ� ������ �� ������, �迭������ �ޱ� ������ ���� �ִ�
	// int foo(int* v, int size); �迭�� ���ɼ� ����
	// int goo(int* v) // �Ѱ��� ������ �ʿ��� ���ɼ� ����

	//int myparamArray[5] = { 4,6,10,20,100 };
	//foo(myparamArray, 5);

	//goo("HelloWorld");
#pragma endregion

	printf("�ĤǤ���;");
	return 0;
}
