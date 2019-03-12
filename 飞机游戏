#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define X 50					//飞机初始位置的横坐标,即机头的位置
#define Y 15					//飞机初始位置的纵坐标,即机头的位置
int x = X, y = Y;		//初始化飞机初始位置
void draw()			//绘制飞机
{
	for (int i = 0; i < y; i++)		//绘制机头
	{
		printf("\n");
	}
	for (int i = 0; i < x; i++)
	{
		printf(" ");
	}
	printf("*\n");
	for (int i = 0; i < x - 2; i++)		//绘制机翼
	{
		printf(" ");
	}
	printf("*****\n");
	for (int i = 0; i < x - 1; i++)		//绘制机尾
	{
		printf(" ");
	}
	printf("* *\n");
}
void attack()			//绘制子弹
{
	system("cls");
	for (int j = 0; j < y; ++j)
	{
		for (int i = 0; i < x; ++i)
			printf(" ");
		printf("|\n");
	}
}

int main()
{
	char input;
	while (1)
	{
		system("cls");
		draw();
		input = _getch();
		if (input == 'w')		//飞机上移
		{
			y--;
		}
		if (input == 'a')		//飞机左移
		{
			x--;
		}
		if (input == 's')		//飞机下移
		{
			y++;
		}
		if (input == 'd')		//飞机右移
		{
			x++;
		}
		if (input == ' ')		//飞机发射子弹
		{
			attack();
		}
	}
}
