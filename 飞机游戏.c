#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
int x = 50, y = 20;			//飞机初始位置
bool attack = false;			//储存开火状态
void draw()				//绘制
{
	if (!attack)						//没有攻击
	{
		for (int i = 0; i < y; i++)			//绘制飞机前的空行
		{
			printf("\n");
		}
	}
	else							//进行攻击
	{
		for (int j = 0; j < y; ++j)			//绘制子弹
		{
			for (int i = 0; i < x; ++i)
				printf(" ");
			printf("|\n");
		}
		attack = false;
		Beep(10000000, 2);
	}
	for (int i = 0; i < x; i++)				//绘制机头所在行前面的空格
	{
		printf(" ");
	}
	printf("*\n");						//绘制机头
	for (int i = 0; i < x - 2; i++)				//绘制机翼
	{
		printf(" ");
	}
	printf("*****\n");
	for (int i = 0; i < x - 1; i++)				//绘制机尾
	{
		printf(" ");
	}
	printf("* *\n");
}

int main()
{
	char input;
	while (1)
	{
		system("cls");
		draw();
		if (_kbhit())				// 判断是否有输入,VS中不允许使用kbhit，这里使用_kbhit代替
		{
			input = _getch();		//VS中不允许使用getch，这里使用_getch代替
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
				attack = true;
			}
		}
	}
}
