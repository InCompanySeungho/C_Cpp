#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>


int main()
{
	/*
	char myString[100];

	fseek(stdin, 0, SEEK_END);
	scanf("%99[^/n]s", myString); // 99[^/n] : 99���� ���ڿ��� �ް� �� �ٲ� ���ڿ��� ���� �ʴ´�.

	//strcpy(myString, "Hello World");
	printf(myString);
	*/

	// strcpy �����ڵ� ( �� ����)
	/*
	char inputString[100];

	printf("���ڿ� : " );
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^/n]s", inputString);


	char duplicatedString[100];
	strcpy(duplicatedString, inputString); // (���� �Ķ����, �� �Ķ���� )
	printf("�Էµ� ���ڿ��� %s .", duplicatedString);
	*/

	// strcmp �����ڵ� 
	/*
	char str1[100];
	char str2[100];
	strcpy(str1, "HelloA");
	strcpy(str2, "HelloB");

	str1[0] ='a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0'; // : null��. �������� 0(null)�� �־���� �� ���ķ� �����Ⱚ�� �ȳ����� ����ε� �������� ���� �� �ִ�.
	//if(str1 == str2) // str1,2 �� �ּҰ��̱� ������ ���� ������ str1,2 �� ���� ����� ���� �� ����
	//if(strcmp(str1,str2) == 0) // ���ڿ��� ���� ������ ���ϱ� ���ؼ��� strcmp�� ����Ͽ� ������ �񱳸� �ؾ���

	int result = strcmp(str1, str2); // strcpm = ������ �� ( -1 , 1 ) ���ٸ� 0

	printf("%d", result);
	*/

	// ������ ���� ���α׷���
	// ���ڿ��� �Է¹޾� �ش� ���ڿ��� �Ųٷ� ����ϴ� ���α׷� (cstring�� �����ϴ� �Լ� ���� ����)
	char str1[100]; // �Է¹��� ���ڿ�
	char str2[100]; // ������ ���ڿ�

	int _arrSize = 0;
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", str1); // �Է� �������� 99[^\n]s
	printf("�Է��� ���ڿ��� : %s ", str1);

	for (int i = 0; ; i++)
	{
		//_arrSize += 1;
		//printf("arrSize : %d\n ", _arrSize);

		if (str1[i] == '\0')
		{
			_arrSize = i;
			printf("_arrSize : %d", _arrSize);
			printf("�극��ũ\n");
			break;
		}
	}

	for (int i = 0; i < _arrSize; i++)
	{
		str2[(_arrSize - i)-1] = str1[i]; // _arrSize = 4 �̱� ������ -1 ������ [0~3]
	}


	str2[_arrSize] = '\0';
	printf("\n������ ���ڿ��� : %s", str2);
	return 0;
}  