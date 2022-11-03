#include"Header.h"
#define INTERVAL 1.0/60.0
#define INTERVAL2 0.016f


int main()
{
	
	float prev = (float)clock() / CLOCKS_PER_SEC;
	Display* display = new Display();
	GameEngie* gameEngine = new GameEngie();
	showConsoleCursor(false);
	//printf("INTERVAL : %.2f", INTERVAL);
	srand(time(0));

	gameEngine->init();
	while (true)
	{
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float delta = curr - prev;
		// curr �� Ŀ������ ���ؼ� delta�� ���� Ŀ��

		//printf("���� ���� ��\n");
		if (delta < INTERVAL)continue; // 1 / 60 �ʸ��� ������ ����ǰ� �Ѵ�.
		//printf("���");
		prev = curr;
		
		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');

		if (left)
		{
			// �������� ��� �̵�
			gameEngine->next(delta, 'a');
		}	
		else if(right)
		{
			gameEngine->next(delta, 'd');
			// ��� �Ʒ��� ������(�ڵ�)
		}
		else if (down)
		{
			gameEngine->next(delta, 's');
		}
		else
		{
			gameEngine->next(delta, 0);
		}

		// ȭ�� ���
		gameEngine->makeDisplayData();
		display->draw();
		
		//if (gameEngine->state ==)// �������� �޾ƿ;���
		{
			//break;
		}

		// ���� ���� �Ǵ�
	}
	return 0;
}