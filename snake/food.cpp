#include "food.h"
food::food()
{
	foodPos.x = rand() % 80 * 10;//��ֹʳ��Բ���
	foodPos.y = rand() % 60 * 10;
	foodFlag = 1;//ʳ�����
}
void food::drawfood()
{
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(foodPos.x, foodPos.y,foodPos.x + 10, foodPos.y + 10);
}
void food::setFoodPos()
{
	//ʳ����ܳ�����������
	foodPos.x = rand() % 60 * 10;//��ֹʳ��Բ���
	foodPos.y = rand() % 59 * 10;
	foodFlag =1;//ʳ�����
}
int& food::getFlag()
{
	return foodFlag;
	//�ı�������������
}
myPoint food::getFoodPos()
{
	return foodPos;
}