#include"EMS.h"

int main()
{
	Employee* employee[100];
	int count = 0; // ó�� ����� = 0
	while (true)
	{
		printf("���� �Է� \n");
		printf("1. ��� ���� \n");
		printf("2. ��� �߰� \n");
		printf("3. ��� ���� \n");
		printf("4. ���α׷� ���� \n");

		int input;

		fseek(stdin, 0, SEEK_END);
		scanf("%d", &input);
		if (input == 1)
		{
			printf("[������� �Է�]\n");
		
			for (int i = 0; i < count; i++)
			{
				employee[i]->printImpormation();
			}
			continue;
		}
		else if (input == 2)
		{
			char* name = getString("����� �Է� : ");
			int gender = getInt("���� �Է�(1 ����, 2 ����) :");
			char* rank = getString("���� �Է� : ");

			Employee* obj = new Employee(name, gender, rank); //new �Ҵ����� ��������
			employee[count] = obj; // �Ҵ� ��ų���� 0
			//employee[count] = new Employee(name, gender, rank);

			count++;
			delete[] name;
			delete[] rank;
			//obj->~Employee();
			//delete obj;
			continue;
		}

		else if (input == 3)
		{
			// ������ �ȵǴ� ����
			int number = getInt("�����ȣ�� �Է� : ");
			int deletedIndex = -1;
			for (int i = 0; i < count; i++)
			{
				if (number == employee[i]->num)
				{
					printf("�Է°� : %d", i);
					delete employee[i];
					deletedIndex = i;
					continue;
				}
			}

			if (deletedIndex >= 0) // ������ �����ߴ�. // �� ���ֱܳ�
			{
				for (int i = deletedIndex; i < count - 1; i++)
				{
					employee[i] = employee[i + 1];
				}
			}

			count--;
			printf("\n���� �Ϸ�\n");
		}
		else if (input == 4)
		{

			printf("���α׷� ����\n");
			break;
		}
		else
		{
			printf("�ùٸ��� ���� ��. �ٽ� �Է����ּ���\n");
			continue;
		}

	}
}

int getInt(const char* prompt)
{
	int input;
	printf("%s", prompt);
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);
	return input;
}

/// <summary>
/// 
/// </summary>
/// <param name="prompt">���� ����ϰ� �� �� : </param>
/// <returns></returns>
char* getString(const char* prompt) // GetString �̶�� �Լ��� ������ �ı��ȴ�.
{
	// �迭 = �ּҰ�
	// �迭 = ������
	//char input[100]; //�̷������� �ۼ��ϸ� ��ȯ�� �ּҰ��� ���� �ı��ȴ�.
	char* input = new char[100]; // new Ű���带 �̿��Ͽ� �����Ҵ�
	printf("%s", prompt);

	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", input);
	//printf("getString �Է� : %s", input);
	return input;
}
