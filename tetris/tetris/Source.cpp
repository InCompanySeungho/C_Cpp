#include"Header.h"
#define INTERVAL 1.0/60.0
int main()
{
	float prev = (float)clock() / CLOCKS_PER_SEC;
	Display* display = new Display();
	GameEngine* _gameEngine = new GameEngine();
	showConsoleCursor(false);

	while (true)
	{
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev;

		if (dt < INTERVAL) continue;
		prev = curr;

		

		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');
		if (left)
		{
			// TODO : ���� Ŭ��
			_gameEngine->next(dt, 'a');
		}
		else if(right)
		{
			_gameEngine->next(dt, 'd');
			// TODO : �׳� ������
		}
		else if (down)
		{
			_gameEngine->next(dt, 's');
		}
		else
		{
			_gameEngine->next(dt, 0);
		}
		// ȭ�����

		_gameEngine->next(dt,0);
		_gameEngine->makeDisplayData();
		display->draw();

		// ���� ���� �Ǻ�
		
	}
	return 0;
}

