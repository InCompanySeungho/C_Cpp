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
				drawPosition(k, i, displayData[i][k] == 1);// GRID �� 0���� �Ҵ�Ǿ��ִ� ����
				// displayData[i][k] ==1 : true /// displayData[i][k] == 0 : false
			}
		}
	}
};

class GameEngie // ���ӵ������� �׸���(�迭)����, ����ں�� ����
{
public:
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = // ���� ��
	{ 
		0,0,0,0,0,0,0, 
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = // ���� ��ϸ�� ����
	{	1,1,1,
		0,0,1,
		0,0,1
	};


	// userBlock�� ��� ��ġ�� �ִ����� ���� y ��ǥ�� �ʿ���
	int blockX = 0;
	int blockY = 0;

	float elapsed = 0.0f;

	void init() // GameEngine �ʱ�ȭ
	{

	}
	// next�� while �������� �Ź� �ҷ����� �Լ�.
	void next(int _delta, char _keyboardInput)
	{
		// ����� ��� ����߷�����
		elapsed += _delta;
		if (elapsed >= 0.5f)
		{
			blockY++;
			//elapsed = 0.0f;
			elapsed = -0.5f;
		}
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
				displayData[i][k] = gameGridData[i][k];
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
					// TODO:
					int _x = k + blockX;
					int _y = i + blockY;

					//displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
					// �ش籸���� | �����ڷ� ª�� �ذ��� �� �ִ�.
					// | ������ : ��Ʈ OR ( �ϳ��� 1�̶�� 1�� ��ȯ��) 
					// -> displayData[][] �� 1�̶�� �� ������, 0�̶�� �� ������ �����Ѵ�.
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // �̷����� �ڵ尡 �� ����
				}
			}
		}
	}

	void draw()
	{

	}
};