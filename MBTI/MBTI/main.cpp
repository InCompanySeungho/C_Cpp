#include"Header.h"
//#include"Header.cpp"



// Value
int arr_Answer[4] = { -3,-1,1,3 };
int curQuest; // 0 = IE, 1 = SN...
struct Question_I_E
{
	int curQuestionCount; // �� ��° ������ �ϰ� �ִ���
	int _score;
	void ChaneScore(int i)
	{

	}
};

int GetAnswer()
{
	printf("[%s]\n" , string_Question_I_E_1);
	printf("����� �ش� ������ ? :  %d, %d, %d, %d : ",
		arr_Answer[0], arr_Answer[1], arr_Answer[2], arr_Answer[3]); // �� �κ��� �����ΰ�? �� �Ҵ��� ���� �ʰ� ������Ѽ�?
		//1, 2, 3, 4);

	int _input;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &_input);
	switch (_input)
	{
	case -3:
		printf("\n����� ������ ���� [%d] �Դϴ�", _input);
		
		break;
	case -1:
		printf("\n����� ������ ���� [%d] �Դϴ�", _input);
		break;
	case 1:
		printf("\n����� ������ ���� [%d] �Դϴ�", _input);

		break;
	case 3:
		printf("\n����� ������ ���� [%d] �Դϴ�", _input);
		break;
	default:
		printf("�ٽ� �Է����ּ���\n");
		break;
	}
	
	return _input;
}

void Question(Question_I_E* _ie)
{
	switch (curQuest) // ���� � ���� ��������
	{
	case 0: // I_E
		switch (_ie->curQuestionCount) // �� �ܰ����� ie ������ ����
		{
		case 0:
			_ie->_score = GetAnswer();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
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
int main()
{
	Question_I_E* ie;
	ie = (Question_I_E*)malloc(sizeof(Question_I_E));
	ie->curQuestionCount = 0;
	//GetQuetionInformation();
	//arr_Answer[0] = 1;
	//arr_Answer[1] = 2;
	//arr_Answer[2] = 3;
	//GetAnswer();
	Question(ie);
	//printf("%s", string_Question_I_E_1);
	return 0;
}


