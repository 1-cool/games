#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int x = 25, y = 6;			//小球的起始位置
	int bottom = 20;			//地面的纵坐标，即小球运动的下界
	int top = 6;				//球运动的上界
	int v = 1;				//小球的速度
	while (top <= bottom)
	{
		y += v;				//移动小球位置
		system("cls");
		for (int i = 0; i < y; i++)			//绘制小球前的空行
			printf("\n");
		for (int i = 0; i < x; i++)
			printf(" ");
		printf("O\n");					//绘制小球
		if (y >= bottom)
		{
			top += 2;				//上界每次向下移动两行
			v = -v;
		}
		if (y <= top)
			v = -v;
		//Sleep(5);
	}
	return 0;
}
