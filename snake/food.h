#ifndef _FOOD_H_
#define _FOOD_H_
#include<graphics.h>
#include "myPoint.h"
class food
{
public:
	food();
	void drawfood();
	void setFoodPos();
	int& getFlag();
	myPoint getFoodPos();
protected:
	myPoint foodPos;
	int foodFlag;//ʳ����ڱ��
};
#endif // !_FOOD_H_
#pragma once
