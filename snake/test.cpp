#include<iostream>
#include "snake.h"
#include "food.h"
/*
δʵ�ֵ�����
1 ���Ѷ��ݼ��л�  yes
2 ���ʳ��ͬʱ���� 
3 ʵʱ��ʾ�ߵĳ��� yes
4 ײǽ���� yes
5 ����Ч��
6 AIģʽ

2021/8/17  �ؿ���
*/ 
using namespace std;
//д������ ��������

snake *pSnake = new snake;
food *pFood = new food;
int SnakeSpeed;

void SetSnakeInit()
{
	pSnake->ReInit();
}

bool GameOver = false;

void eatFood(snake* pSnake, food *pFood)
{
	//���������ʱ��
	//������ʱ�����Ա���ṩ�˹��нӿ�
	if (pSnake->getSnakePos(0).x == pFood->getFoodPos().x&&
		pSnake->getSnakePos(0).y == pFood->getFoodPos().y)
	{
		//��Ϸ����
		pSnake->getSnakeSize()++;
		pFood->getFlag() = 0;
	}
}

bool GameLevel() //������Ϸ�Ѷ�
{   
	bool other = false;
	char userkey = 49;
	//userkey = _getch();
	while(1) {
		other = false;
		if (_kbhit())
		{

			userkey = _getch();//conio.h
			switch (userkey)
			{
			case 49:
				pSnake->SetSnakeSpeed(100);
				break;
			case 50:
				pSnake->SetSnakeSpeed(50);
				break;
			case 51:
				pSnake->SetSnakeSpeed(20);
				break;
			case 52:
				GameOver = true;
				break;
			default:
				other = true;
				break;
				
			}
			if(!other)
			return true;
		}
	}
	return false;
}


void GameOn()//������Ϸ����ʱ�Ҳ�Ľ���
{
	setfillcolor(RGB(220,20,60));//��ɫ
	fillrectangle(600, 0, 610, 600);
	setfillcolor(RGB(220, 20, 60));//��ɫ
	fillrectangle(0, 590, 600, 600);
	setfillcolor(RGB(0, 139, 139));//��ɫ
	fillrectangle(610, 150, 1000, 160);
	setfillcolor(RGB(0, 139, 139));//��ɫ
	fillrectangle(610, 300, 1000, 310);

	char str[32];
	char str2[64];
	char str3[64];
	char str4[64];
	char str5[64];
	char str6[64];
	int score = pSnake->getSnakeSize();
	settextcolor(0x40E0D0);
	//settextstyle(50, 0, "����");
	sprintf_s(str, "�߳���%d\n", score);	//��ʽ������ת�ַ���
	settextstyle(40, 0, "����");
	outtextxy(700, 50, str);
	if(pSnake->getSnakeSpeed()==100) sprintf_s(str2, "�Ѷȼ��𣺼򵥼���", score);
	else if(pSnake->getSnakeSpeed()==50) sprintf_s(str2, "�Ѷȼ�����ͨ����", score);
	else sprintf_s(str2, "�Ѷȼ��𣺵�������", score);
	//��ʽ������ת�ַ���
	outtextxy(630, 200, str2);

	sprintf_s(str3, "���ϰ� W", score);
	outtextxy(630, 350, str3);

	sprintf_s(str4, "���°� S", score);
	outtextxy(630, 510, str4);

	sprintf_s(str5, "���Ұ� D", score);
	outtextxy(800, 350, str5);

	sprintf_s(str6, "���� A", score);
	outtextxy(800, 510, str6);
}

 
void GameStart()
{
	cleardevice();
	char str[64];
	settextcolor(0x40E0D0);
	 settextstyle(40, 0, "����");
	sprintf_s(str,"̰������Ϸ(Made by GJY)");
	outtextxy(250, 150, str);
	
	setfillcolor(RGB(220, 20, 60));//��ɫ  ���
	fillrectangle(100,300, 900, 305);

	setfillcolor(RGB(220, 20, 60));//��ɫ  ���2
	fillrectangle(100, 500, 900, 505);

	setfillcolor(RGB(220, 20, 60));//��ɫ  ����1
	fillrectangle(300, 300, 305, 505);

	char str1[64];
	settextcolor(0x40E0D0);
	settextstyle(30, 0, "����");
	sprintf_s(str1, "��ģʽ��1");
	outtextxy(100, 400, str1);

	setfillcolor(RGB(220, 20, 60));//��ɫ  ����2
	fillrectangle(500, 300, 505, 505);

	char str2[64];
	settextcolor(0xFF00FF);
	settextstyle(30, 0, "����");
	sprintf_s(str2, "�е�ģʽ��2");
	outtextxy(320, 400, str2);

	setfillcolor(RGB(220, 20, 60));//��ɫ  ����3
	fillrectangle(700, 300, 705, 505);

	char str3[64];
	settextcolor(0x0000FF);
	settextstyle(30, 0, "����");
	sprintf_s(str3, "����ģʽ��3");
	outtextxy(520, 400, str3);

	char str4[64];
	settextcolor(0xD4F2E7);
	settextstyle(30, 0, "����");
	sprintf_s(str4, "�˳���Ϸ��4");
	outtextxy(720, 400, str4);
	 
	while (1)
	{
		if (GameLevel())
			break;
	}
}

 

void SnakeMain()
{

	cleardevice();//ˢ��ҳ��
	int cnt = 0;

	while (1)
	{
		cnt++;
		char strOver[50];
		int score = pSnake->getSnakeSize();
		//sprintf_s(str, "������%d", score);	//��ʽ������ת�ַ���
		//outtextxy(0, 0, str);	//������� ������100

		cleardevice();//ˢ�±���
		GameOn();

		if (pFood->getFlag() == 0||(pSnake->getSnakeSpeed()==30)&&cnt==5)
		{
			cnt = 0;
			pFood->setFoodPos();
		}

		pSnake->drawSnake();
		pSnake->moveSnake();
		eatFood(pSnake, pFood);
		pFood->drawfood();
		//ֻ�е��а���ʱ�Ŵ��� ���������ж�
		if (pSnake->GetOver())
		{
			settextcolor(0x0000FF);
			sprintf_s(strOver, "Game Over! ����߳���%d  �����Զ����ز˵�", score);	//��ʽ������ת�ַ���
			outtextxy(20, 40, strOver);
			Sleep(2000);
			break;
		}
		if (_kbhit())
		{
			pSnake->keyDown();
		}
		Sleep(pSnake->getSnakeSpeed());
	}

}

int main()
{
	initgraph(1000, 600);//����һ������
	setbkcolor(BLACK);//������ɫ
	while (!GameOver)
	{
		GameStart();
		if (GameOver) return 0;

		SnakeMain();
		SetSnakeInit();
	}
	_getch();
	closegraph();
	system("pause");
	return 0;
}