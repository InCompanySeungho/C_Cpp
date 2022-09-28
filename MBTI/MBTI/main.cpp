#include"Header.h"
using namespace std;

// Value
int arr_Answer[4] = { 1,2,3,4 };
int curQuest; // 0 = IE, 1 = SN... ���� � ī�װ��� ������ �ް� �ִ���

char MBTI[4];
/// <summary>
/// [a][b] // a : � �������� 0~3, b : �� ��° �������� 0~3
/// </summary>
const char* string_Question[4][4] =
{
	string_Question_I_E_1,string_Question_I_E_2,string_Question_I_E_3,string_Question_I_E_4,
	string_Question_S_N_1,string_Question_S_N_2,string_Question_S_N_3,string_Question_S_N_4,
	string_Question_T_F_1,string_Question_T_F_2,string_Question_T_F_3,string_Question_T_F_4,
	string_Question_J_P_1,string_Question_J_P_2,string_Question_J_P_3,string_Question_J_P_4,
};

struct STRUCT_Question
{
	int curQuestionCount = 0; // �� ��° ������ �ϰ� �ִ���
	int _result[4]; // �� �迭�� ��� ����
	int _FinalValue = 0; // ���� ��ġ��

	void QuestionInit()
	{
		curQuestionCount = 0;
		_FinalValue = 0;
	}
	void ChaneScore() // 1~4 ��ȣ ���� �� ġȯ -3 -1 1 3
	{
		for (int i = 0; i < 4; i++)
		{
			switch (_result[i])
			{
			case 1:
				_FinalValue -= 3;
				break;
			case 2: _FinalValue -= 1;
				break;
			case 3:
				_FinalValue += 1;
			case 4:
				break;
				_FinalValue += 3;
				break;
			default:
				_FinalValue += 0;
				break;
			}
		}
	}

	char ProduceResult(char a, char b)
	{
		if (_FinalValue >= 0) // 0 �̻��� �� ���ʴ� ���´�.
		{
			return b;
		}
		else
		{
			return a;
		}
	}
};
/// <summary>
/// ù ��° ��� ��, �� ���� �̾�� Ȯ��
/// </summary>
/// <param name="_inputValue">ó�� �Է��� ��</param>
int AskAgain(int& _finalreturnValue)
{
	//int _finalreturnValue;

	int _temp = _finalreturnValue;

	char againInput = NULL; // �Է��� �� Ȯ�� or �ٽ� �Է��ϱ� :: �Է�Ȯ�ο� ����
	// againInput�� char ������ ���� ��, ��ȯ�� �� int ������ ����ȯ ��Ŵ

	bool isEnd = false;
	while (!isEnd)
	{
		printf("\n ����� ������ ���� [%d] �Դϴ�", _temp);
		printf("\n �ٽ� �����Ͻ÷��� ���ڸ� , ���� ������ �����Ϸ��� Enter�� �Է����ּ��� : \n");

		fseek(stdin, 0, SEEK_END);
		//againInput = NULL;
		//againInput = getchar(); // scanf_s ���� '\n'�� �ν��� ���ؼ� getchar() �Լ��� ����ؾ߰ڴ�
		scanf_s("%c", &againInput); // Enter �� ASCII �ڵ带 �˾ƿ;��� = '\n'

		if (againInput == '\n') // Enter �Է��� ���� ���� ���� ������ ,�ƴϸ� AskAgain �ٽ�
		{
			//Sleep(1000);
			printf("'%d' �� �����ϼ̽��ϴ�. ���� ������ �����մϴ�.\n\n", _temp); // �̷��� �ϸ� �ƽ�Ű�ڵ� ���� ����.
			isEnd = true; // ���⼭ ����
		}
		else
		{
			//if ((int)againInput == arr_Answer[0] || (int)againInput == arr_Answer[1] || 
				//(int)againInput == arr_Answer[2] || (int)againInput == arr_Answer[3] ) // [ o ] 
			if (againInput == '1' || againInput == '3' ||
				againInput == '2' || againInput == '4') // [ o ] 
			{
				_temp = NULL; // ���� �ٲ�� �Ǵϱ� _temp �ʱ�ȭ
				_temp = againInput - '0'; // �ٸ� �� ���� // chat to int �ϴ¹� = '0' �� �����μ� �ƽ�Ű�ڵ尪�� ��������� ��ȯ��Ŵ
				printf("�ٸ� ���� �Է����� : [%c]\n", againInput);
			}
			else // [ x ] 
			{
				printf("������ ���Ե��� �ʴ� ���� �Է��Ͽ���. �ٽ� �Է���! \n");
			}
			continue; // AskAgain�� �ٽ� ���� ���ؼ� continue;
		}
	} // While ����
	return _temp;
	// AskAgain �Լ��� ������ GetAnswer() �� ��ȯ�ȴ�.
}
/// <summary>
/// �� �Է��� ��ȯ�Ͽ� ������ score �� �ջ�ȴ�.
/// </summary>
/// <returns></returns>
int AnswerInput() // call by reference �� �����ؾ� ie->score �� ���� ����ǰ� �� �� ����
{
	bool isEnd = false;
	while (!isEnd)
	{
		//printf("\nAnswerInput ���� ���ϴ�! \n ");
		int _input;
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &_input);
		switch (_input)
		{
		case 1:
			return AskAgain(_input); // ������ ��. ie->score �� �Ҵ��Ѵ�.
			isEnd = true;
			break;
		case 2:
			return AskAgain(_input); // ������ ��. ie->score �� �Ҵ��Ѵ�.
			isEnd = true;
			break;
		case 3:
			return AskAgain(_input); // ������ ��. ie->score �� �Ҵ��Ѵ�.
			isEnd = true;
			break;
		case 4:
			return AskAgain(_input); // ������ ��. ie->score �� �Ҵ��Ѵ�.
			isEnd = true;
			return _input;
		default:
			printf("������ ���Ե��� ���� �� �Դϴ�. �ٽ� �Է����ּ���\n");
			continue;//�ٽ� �Է��ؾ� �ϴϱ� ��ͽ�Ŵ
		}
	}
}
int GetAnswer(const char* _char)
{
	//printf("���� : [%s]\n", string_Question_I_E_1);
	printf("���� : [%s]\n", _char);
	printf("���� �ش� ������ ? \n�׷��� �ʴ١� [%d] , [%d] , [%d] , [%d] ��ſ� �׷���\n",
		arr_Answer[0], arr_Answer[1], arr_Answer[2], arr_Answer[3]);

	return AnswerInput();
}

void Question(STRUCT_Question* _question)
{
	//printf("�����ϴ� ����Ʈ : %s");
	bool isQuestionEnd = false;
	while (!isQuestionEnd) // ����Ʈ �� �ƴ� ����
	{
		if (_question->curQuestionCount == 3) // ���� ���� ī�װ��� �̵�
		{
			_question->_result[_question->curQuestionCount] = GetAnswer(string_Question[curQuest][_question->curQuestionCount]);
			_question->ChaneScore(); // ���� ġȯ

			curQuest += 1;
			isQuestionEnd = true;

			printf("���� ����ī�װ��� �����մϴ�\n");
			Sleep(1000);

			break;
		}
		else
		{
			//printf("\n%s", string_Question[curQuest][_question->curQuestionCount]);
			_question->_result[_question->curQuestionCount] = GetAnswer(string_Question[curQuest][_question->curQuestionCount]);
			_question->curQuestionCount += 1;
			continue;
		}
	}
	printf("\n\nQuestion �Լ� Ż��.");
}
void ResultPrint(char a, char b, char c, char d)
{
	printf("\n��� ���\n");
	MBTI[0] = a;
	MBTI[1] = b;
	MBTI[2] = c;
	MBTI[3] = d;
	printf("\n\n\n ����� MBTI�� : %s", &MBTI);

	if (strcmp(MBTI, "ISTJ") == 0)
	{
		printf("\n�����MBTI�� ���� ����� ǻ������");
	}
}
void Intro()
{
	printf("�� MBTI�׽�Ʈ ����� �� \n");
}
int main()
{
	Intro();
	STRUCT_Question* ie; // ���� / ����
	STRUCT_Question* sn; // ���� / ����
	STRUCT_Question* tf; // ��� / ����
	STRUCT_Question* jp; // �Ǵ� / �ν�
	ie = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	sn = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	tf = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	jp = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	curQuest = 0;
	ie->QuestionInit();
	sn->QuestionInit();
	tf->QuestionInit();
	jp->QuestionInit();


	Question(ie);
	Question(sn);
	Question(tf);
	Question(jp);


	

	ResultPrint(
		ie->ProduceResult('I', 'E'), 
		sn->ProduceResult('S', 'N'),
		tf->ProduceResult('T', 'F'),
		jp->ProduceResult('J', 'P')
		);
	return 0;
}



