#include<stdio.h>

int GetInput();
int main()
{
	int _valueInput1;
	int _valueInput2;
	int _valueOperation;
	printf("Input 1�� ���� �Է��ϼ��� : ");
	_valueInput1 = GetInput();
	printf("\nInput 2�� ���� �Է��ϼ��� : ");
	_valueInput2 = GetInput();

	printf("\nOperation �� ���� �Է��ϼ��� : ");
	_valueOperation = GetInput();

	if (_valueOperation == 0) // ���ϱ�
	{
		printf("\n\nOperation =  0, ���ϱ� �Դϴ�.\n");
		int returnvalue = _valueInput1 + _valueInput2;
		printf("����� %d", returnvalue);
		printf("�Դϴ�");
	}
	else if (_valueOperation == 1) // ����
	{
		printf("\n\nOperation =  1, ���� �Դϴ�.\n");
		int returnvalue = _valueInput1 - _valueInput2;

		printf("����� %d",returnvalue);
		printf("�Դϴ�");
	}
	else if (_valueOperation == 2) // �ŵ�����
	{
		printf("\n\nOperation =  2, �ŵ����� �Դϴ�.\n");
		
		int _destinationValue = 1;
		for (int i = 0; i < _valueInput2; i++)
		{
			_destinationValue *= _valueInput1;
		}
		printf("����� % d", _destinationValue);
		printf("�Դϴ�");
	}
	else // ��������
	{
		printf("������ �߻��Ͽ����ϴ�");
	}


	return 0;
}

//fseek(stdin, 0, SEEK_END);// scanf�� ����ϱ� �� ȣ������� �ϴ� ���� ( �Է°��� �� �� �����°��� �������ش�. )

int GetInput()
{
	int _inputValue;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &_inputValue);
	return _inputValue;
}