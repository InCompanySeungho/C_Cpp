#include"Header.h"

int main()
{
	/*
	int* myArray;
	int input;
	fseek(stdin, 0, SEEK_END);
	printf("���ڸ� �Է��ϸ� �迭 ����  : ");
	scanf("%d", &input);

	myArray = (int*)malloc(sizeof(int) * input); // �����迭 �Ҵ�
	// ������ ������ Ÿ������ ������ ������ (int*)�� ����ȯ ���ش�.

	for (int i = 0; i < input; i++)
	{
		myArray[i] = i * 10;
	}
	for (int i = 0; i < input; i++)
	{ 
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}*/

	// ��������� ���ڸ� �Է¹޾� �迭�� �����Ҵ��� Ȱ���� �Է¹��� ���� ��ŭ�� ũ�⸦ ���� �迭�� �����
	// �ش� �迭�� 2,4,6,8 �� �����ϴ� ������ ������ ��, �迭�� ����϶�

	int* myArray; // �Է¹��� ���� ��ŭ�� ũ�⸦ ���� �迭 : ������ �� �迭 . int* myArray �� int myArray[(int)]
	int input; // �Է¹��� ��. 

	printf("�Է¹��� �� : ");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);

	myArray = (int*)malloc(sizeof(int) * input); // (int*) �� ���ٸ� void* ������ ���� �ȴ�.
	
	for (int i = 0; i < input; i++)
	{
		// �迭�� ���� ����
		myArray[i] = (i+1) * 2;
	}
	for (int i = 0; i < input; i++)
	{
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}

	free(myArray);
	return 0;
}