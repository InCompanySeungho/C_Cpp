#include"Header.h"
//#include"Header.cpp"
using namespace std;
// Value
int arr_Answer[4] = { 1,2,3,4 };
int curQuest; // 0 = IE, 1 = SN...
struct Question_I_E
{
	int curQuestionCount; // �� ��° ������ �ϰ� �ִ���
	int _score;
	void ChaneScore(int i)
	{
		
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
			printf("'%d' �� �����ϼ̽��ϴ�. ���� ������ �����մϴ�. ", _temp); // �̷��� �ϸ� �ƽ�Ű�ڵ� ���� ����.
			isEnd = true; // ���⼭ ����
		}
		else
		{
			//if ((int)againInput == arr_Answer[0] || (int)againInput == arr_Answer[1] || 
				//(int)againInput == arr_Answer[2] || (int)againInput == arr_Answer[3] ) // [ o ] 
				if (againInput == '1' || againInput == '3' ||
					againInput == '2'|| againInput == '4' ) // [ o ] 
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
int GetAnswer()
{
	printf("���� : [%s]\n", string_Question_I_E_1);
	printf("���� �ش� ������ ? \n�׷��� �ʴ١� [%d] , [%d] , [%d] , [%d] ��ſ� �׷���\n",
		arr_Answer[0], arr_Answer[1], arr_Answer[2], arr_Answer[3]);

	return AnswerInput();
}

void Question(Question_I_E* _ie)
{
	switch (curQuest) // ���� � ���� ��������
	{
	case 0: // I_E
		switch (_ie->curQuestionCount) // �� �ܰ����� ie ������ ����
		{
		case 0:
			_ie->_score += GetAnswer(); // ���ϴ°ŷ� �ؾ� �ջ��� ��
			_ie->curQuestionCount += 1;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			//
			break;
		default:
			break;

			break;
		}
	default:
		break;
	}
}

void GetQuetionInformation()
{
	Question_I_E* ie;
	ie = (Question_I_E*)malloc(sizeof(Question_I_E));
	ie->curQuestionCount = 0;
	printf("IE�� ����Ʈ ī��Ʈ : %d", ie->curQuestionCount);
}

void Intro()
{
	printf("�� MBTI�׽�Ʈ ����� �� \n");
}
int main()
{
	Intro();
	Question_I_E* ie;
	ie = (Question_I_E*)malloc(sizeof(Question_I_E));
	ie->curQuestionCount = 0; // ����ü ������ ��� // ��ȯ �� �������� ��� �����������
	Question(ie);
	
	return 0;
}



