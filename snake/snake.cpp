#include "snake.h"
snake::snake()//���캯��
{
	SnakeSpeed = 50;
	snakeSize = 3;
	//���߳�ʼ��
	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = 10 * i;
		snakePos[i].y = 50;
	}//һ�ڳ�10��λ
	position = right;//��ʼ������

}
void snake::drawSnake()//����
{
	for (int i = 0; i < snakeSize; i++)
	{
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//��ɫ
		fillrectangle(snakePos[i].x, snakePos[i].y, snakePos[i].x + 10, snakePos[i].y + 10);
		//������

	}
}
void snake::moveSnake()//�ƶ���
{
	//������ͷ֮��Ķ���
	for (int i = snakeSize - 1; i > 0; i--)
	{
		snakePos[i].x = snakePos[i - 1].x;
		snakePos[i].y = snakePos[i - 1].y;
	}
	//������ͷ
	switch (position)
	{
	case right:
		snakePos[0].x += 10;
		break;
	case left:
		snakePos[0].x -= 10;
		break;
	case up:
		snakePos[0].y -= 10;
		break;
	case down:
		snakePos[0].y += 10;
		break;

	}
}
void snake::keyDown()//����������
{
	//����Ψһ�ı���ͷ�ķ���
	char userkey = 0;
	userkey = _getch();//conio.h
	switch (userkey)
	{//������� ������С����
	case 'w':
	case 'W':
	case 72: 
		if (position != down)
		{
			position = up;
		}
		break;

	case 's':
	case 'S':
	case 80:
		if (position != up)
		{
			position = down;
		}
		break;

	case 'a':
	case 'A':
	case 75:
		if (position != right)
		{
			position = left;
		}
		break;

	case 'd':
	case'D':
	case 77:
		if (position != left)
		{
			position = right;
		}
		break;

	}
}
//��ķ�װ��
int & snake::getSnakeSize()//�޸��߳��ȵĽӿ�
{
	return snakeSize;
}
myPoint snake::getSnakePos(int pos)//��ȡ�ߵ�pos�ڵ�����
{
	return snakePos[pos];
}
bool snake::GetOver()
{
	if (snakePos[0].x == 0 || snakePos[0].x == 600 || snakePos[0].y == 0 || snakePos[0].y == 590)
	{
		return true;
	}
	return false;
}

void snake::ReInit()
{
	SnakeSpeed = 50;
	snakeSize = 3;
	//���߳�ʼ��
	for (int i = 0; i < snakeSize; i++)
	{
		snakePos[i].x = 10 * i;
		snakePos[i].y = 50;
	}//һ�ڳ�10��λ
	position = right;//��ʼ������
}

void snake::SetSnakeSpeed(int sp)
{
	SnakeSpeed = sp;
}

int & snake::getSnakeSpeed()
{
	return SnakeSpeed;
}