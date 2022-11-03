#define CRT_SECURE_NO_WARNINGS_

#include "TetrisHelper.h"
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>

#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBLOCK_SIZE 3

int displayData[GRID_HEIGHT][GRID_WIDTH] ={ 0, };

// 2��° ���� 16:35����

// �迭�� ���� ���� displayData[3][2] �̶�� �̷� ������ �ȴ�.
/*
	14
	25
	36
*/

class Display
{
public:
	void draw()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				drawPosition(k, i, displayData[i][k] == 1);  // displayData[i][k] == 1 �ϴ� true �� ��ȯ�Ѵ�.
			}
		}
	}
};

class GameEngine
{
public:
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{1,1,0,0,0,0,0},
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{1,1,1},
		{0,0,1},
		{0,0,1}
	};
	int blockX=0; // userBlock�� x ��ǥ��
	int blockY=0; // userBlock�� y ��ǥ��

	float elapsed = 0.0f;
	float controlCheck;
	void init()
	{
		// GameEngine�ʱ�ȭ
	}

	void next(float dt, char keyboardInput) // while�������� �Ź� �ҷ����� �Լ�.
	{

		elapsed += dt;
		if (elapsed >= 0.5f)
		{
			if (canGoDown())
			{
				blockY++;
			}
			else
			{
				// userblock�� gameGridData�� ����
				transcription();
			}

			elapsed -= 0.5f;
		}
		controlCheck += dt;

		if (keyboardInput == 'a'&& canGoLeft() && controlCheck > 0.1f)
		{
			blockX--;
			controlCheck = 0.0f;
		}
		if (keyboardInput == 'd' && canGoRight() && controlCheck > 0.1f)
		{
			blockX++;
			controlCheck = 0.0f;
		}
		if (keyboardInput == 's' && controlCheck > 0.1f)
		{
			blockY++;
			controlCheck = 0.0f;
		}
	}

	bool canGoDown() // ������ �� �ֳ�.
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				// i  : 
				if (userBlock[i][k] == 1 && i + blockY + 1 >= GRID_HEIGHT)
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY + 1][k + blockX] == 1)
					return false;
				else
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
				if (userBlock[i][k] == 1 && k + blockX - 1 < 0) // ��ü ��ũ�� ���� ����
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX - 1] == 1) // ����Ǿ��ִ� ������ ���� ��������
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
				if (userBlock[i][k] == 1 && k + blockX + 1 > GRID_WIDTH -1) // ��ü ��ũ�� ���� ����
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX + 1] == 1) // ����Ǿ��ִ� ������ ���� ��������
					return false;
			}
		}

		return true;
	}

	void transcription() // userBlock �� gameGrid�� �����ϴ� �Լ�
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{	
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				//makeDisplayData ó�� ����ȭ ����
				int _x = k + blockX;
				int _y = i + blockY;
				gameGridData[_y][_x] = userBlock[i][k] | gameGridData[_y][_x];
			}
		}
		// �� ���� ���� �� �ִ��� Ȯ��
		// ���ο� ��� ����
		makeUserBlock();
	}

	void makeUserBlock()
	{
		blockX = 0;
		blockY = 0;
		// TODO ������ ���ؼ� ���ο� ��� ����
	}
	// ���� ���� �����͸� ȭ�鿡 ����� �� �ִ� �����ͷ� ����
	void makeDisplayData()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				displayData[i][k] = gameGridData[i][k];
			}
		}

		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				// i = userBlock �� ������, blockY = userBlock�� y��ǥ
				if (i + blockY < 0 || i+blockY > GRID_HEIGHT)
				{
					// DONOTHING
				}
				else if (k + blockX <0 || k + blockX> GRID_WIDTH)
				{
					// DONOTHING
				}
				else
				{
					// TODO : GridData �������� �ʰ� �ϱ�
					//displayData[i + blockY][k + blockX] = userBlock[i][k]; // userBlock ��ü�� �״�� �ִ� ���̱� ������, �̹� ä���� �ִ� ������ �־ userBlock���� ����ִٸ� ����ְ� �ȴ�.
					//displayData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[i + blockY][k + blockX]; -> ���� ���̱�

					int _x = k + blockX;
					int _y = i + blockY;
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x];
				}
			}
		}
	}	
};