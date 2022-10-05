#include"Header.h"
#define INTERVAL 1.0/60.0 // 0.016��(60)�������� ����� ���ؼ�
#define INTERVAL2 0.016f


int main()
{
	
	float prev = (float)clock() / CLOCKS_PER_SEC;
	Display* display = new Display();
	GameEngie* gameEngine = new GameEngie();
	showConsoleCursor(false);

	//printf("INTERVAL : %d", INTERVAL);
	while (true)
	{
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float delta = curr - prev;
		// curr �� Ŀ������ ���ؼ� delta�� ���� Ŀ��

		//printf("���� ���� ��\n");
		if (delta < INTERVAL)continue; // 1 / 60 �ʸ��� ������ ����ǰ� �Ѵ�.
		
		//printf("���� ���� ��\n");
		prev = curr;
		
		
		//print("%.3f", curr);
		
		bool left = keyState('a');
		bool right = keyState('d');

		if (left)
		{
			// �������� ��� �̵�
		
		}
		else
		{
			// ��� �Ʒ��� ������(�ڵ�)
		}
		gameEngine->next(delta, 0);

		// ȭ�� ���
		gameEngine->makeDisplayData();
		display->draw();
		
		// ���� ���� �Ǵ�
	}
	return 0;
}