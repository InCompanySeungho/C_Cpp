#pragma once
#pragma warning(disalbe:4996)
#include"TetrisHelper.h"
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdlib>

// �ý��� �߻�ȭ
#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBLOCK_SIZE 3 


// ���������� ���� 
int displayData[GRID_HEIGHT][GRID_WIDTH]{ 0, }; // �迭 �ʱ�ȭ [��][����]. [y][x]

class Display
{
public:
	void draw()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				if (displayData[i][k] == 0) // ����ִٸ�
				{
					drawPosition(k, i, false);
				}
				else
					drawPosition(k, i, true);

				// �� ª�Ծ���
				// drawPosition(k, i, displayData[i][k] == 1);// GRID �� 0���� �Ҵ�Ǿ��ִ� ����
				// displayData[i][k] ==1 : true /// displayData[i][k] == 0 : false


			}
		}
	}
};

class GameEngie // ���ӵ������� �׸���(�迭)����, ����ں�� ����
{
public:
	enum class GameState
	{
		PLAYING, GAMEOVER
	};
	GameState state = GameState::PLAYING;

	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = // ���� ��
	{
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{1,1,1,0,0,0,0,},
		{1,1,1,1,1,1,1,},
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = // ���� ��ϸ�� ����
	{ 0,
	};

	int userBlockVarious[3][USERBLOCK_SIZE][USERBLOCK_SIZE] =
	{
		{
		{0,1,0,},
		{0,1,0},
		{0,1,0},
		},
		{
			{0,0,0,},
			{0,1,1,},
			{0,1,1,},
			},
		{
			{0,0,0,},
			{0,1,0,},
			{1,1,0,},
		},
	};
		// userBlock�� ��� ��ġ�� �ִ����� ���� y ��ǥ�� �ʿ���
	int blockX = 0;
	int blockY = 0;

	float elapsed = 0.0f;
	float controlCheck = 0.0f;
	void init() // GameEngine �ʱ�ȭ
	{

	}

	// next�� while �������� �Ź� �ҷ����� �Լ�. 1/60 �� ���� �����
	void next(int _delta, char _keyboardInput)
	{
		if (state == GameState::GAMEOVER)
			return;
		// ����� ��� ����߷�����
		elapsed += _delta;
		if (elapsed >= 0.5f)
		{
			if (canGoDown())
			{
				blockY++;
				if (gameOverDecision()) state == GameState::GAMEOVER;
			}
			else
			{
				// userBlock �� gameGridData�� �����ϸ� �ȴ�.
				trans();
			}
			elapsed = -0.5f;
		}

		controlCheck = controlCheck + _delta;
		if (_keyboardInput == 'a' && canGoLeft() && controlCheck > 0.1f)
		{
			blockX--;
			controlCheck = 0.0f;
		}
		if (_keyboardInput == 'd' && canGoRight() && controlCheck > 0.1f)
		{
			blockX++;
			controlCheck = 0.0f;
		}
		if (_keyboardInput == 's' && canGoDown() && controlCheck > 0.1f)
		{
			blockY++;
			controlCheck = 0.0f;
		}
	}

	// ����� �Ʒ��� ������ �� �ֳ�
	bool canGoDown()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && // �̵��Ϸ��� ĭ�� ����� �����ϰ� �ִ�.
					i + blockY + 1 >= GRID_HEIGHT) // ���� ����� Y�� ��ġ�� ���� ĭ(i + blockY + 1) �� ���� ���̴�.
				{
					return false;

					if (userBlock[i][k] == 1 //
						&& gameGridData[i + blockY + 1][k + blockX] == 1)
					{
						return false;
					}
				}
				else
					// �Ʒ�ĭ�� ����� ���ų�, ���� ���� �ƴϴ�.
					return true;
			}
		}

	}

	bool canGoLeft()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 &&
					k + blockX - 1 < 0) // �·� �̵� �Ұ�
					return false;

				if (userBlock[i][k] == 1
					&& gameGridData[i + blockY][k + blockX - 1] == 1) // 
					return false;

			}
		}
		return true;
	}
	bool canGoRight()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 &&
					k + blockX + 1 > GRID_WIDTH - 1) // ��� �̵� �Ұ�
					return false;

				if (userBlock[i][k] == 1
					&& gameGridData[i + blockY][k + blockX + 1] == 1) // 
					return false;

			}
		}
		return true;

	}

	bool isLineFilled(int y)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (gameGridData[y][i] == 0)return false;
		}
		return true;
	}
	void eraseLine(int y)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			gameGridData[y][i] = 0;
		}
	}

	// y ��ǥ�� �������� �� ĭ�� �Ʒ��� ����
	void drop(int y)
	{
		for (int i = y; i >= 0; i--) // �Ʒ�ĭ ���� �����Ͽ� �� ĭ �� �������Ѵ�.
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
			}
		}
	}
	// userblock�� gameGrid�� �����ϴ� �Լ�
	void trans()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				// makeDispalyData ó�� ����ȭ�� ����.
				gameGridData[i + blockY][k + blockX] =
					userBlock[i][k] == 1 ?
					userBlock[i][k] : gameGridData[i + blockY][k + blockX];
			}
		}
		// TODO : �� ���� ���� �� �ִ��� Ȯ��
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			if (isLineFilled(i))
			{
				eraseLine(i);
				drop(i);
			}
		}
		// ���ο� ��ϻ���
		makeUserBlock();

	}


	bool gameOverDecision()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX] == 1)
				{
					return true; // ���ӿ���
				}
			}
		}
		return false;
	}
	void makeUserBlock()
	{
		blockX = GRID_WIDTH /2 - USERBLOCK_SIZE/2;
		blockY = 0;



		int various = rand() % 3;
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				userBlock[i][k] = userBlockVarious[various][i][k];
			}
		}
		// TODO : ������ ���ؼ� ���ο� ����� �����.

	}

	//displayData�� gameGridData�� �������ִ� �۾�
	// ���� ���� �����͸� ȭ�鿡 ����� �� �ִ� �����ͷ� ��ü
	void makeDisplayData()
	{
		// ���� ����. ����� ��� �� �ִ���
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				displayData[i][k] = gameGridData[i][k]; // �ʱ�ȭ������ ���� gridData�� �޾ƿ´�.
			}
		}

		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (i + blockY < 0  // userblock�߿��� y��ǥ�� ��ġ�� 0���� ����. �׸��庸�� ���� ������ (�迭����� �Ѿ) 
					|| i + blockY > GRID_HEIGHT) // �׸����� �ִ� ũ�⺸�� ŭ (�迭����� �Ѿ)
				{
					// DO NOTHING
				}
				else if (k + blockX < 0 || k + blockX > GRID_WIDTH)
				{
					// DO NOTHING
				}
				else
				{
					// CONDITION : ���� ��ϰ� ���� ����� ������
					// BECAUSE : userBlock �� 0�κ��� gameGridData�� 1 �κ��̾ 0���� �ٲ�����ϱ�, ���� �ı���
					// TODO:
					int _x = k + blockX;
					int _y = i + blockY;

					displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
					// �ش籸���� | �����ڷ� ª�� �ذ��� �� �ִ�.
					// | ������ : ��Ʈ OR ( �ϳ��� 1�̶�� 1�� ��ȯ��) Bitwise
					// -> displayData[][] �� 1�̶�� �� ������, 0�̶�� �� ������ �����Ѵ�.
					//displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // �̷����� �ڵ尡 �� ����
				}
			}
		}
	}
};