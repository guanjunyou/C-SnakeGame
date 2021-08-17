//ר������Ҫ��������#pragma once
#ifndef _SNAKE_H_
#define _SNAKE_H_
#include<graphics.h>//ͼ�λ����
#include<conio.h>//��������
#include "myPoint.h"//�������

class snake
{
public:
	snake();//���캯��
	void drawSnake();//����
	void moveSnake();//�ƶ���
	void keyDown();//����������
	//��ķ�װ��
	int & getSnakeSize();//�޸��߳��ȵĽӿ�
	myPoint getSnakePos(int Pos);//��ȡ�ߵ�pos�ڵ�����
	bool GetOver();//ײǽ����
	void ReInit();//������
	void SetSnakeSpeed(int sp);
	int & getSnakeSpeed();

protected:
	//�����ص�
	int SnakeSpeed;
	myPoint snakePos[100];//�����100�� �洢ÿһ������
	int snakeSize;//��ǰ����
	char position;//�߷���
	//�ѷ���ö�ٳ���
	enum direction { right, left, down, up };
	
};
#endif // !_SNAKE_H_
