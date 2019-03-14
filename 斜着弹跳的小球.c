#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	int x = 0, y = 10;				//小球的起始位置
	int bottom = 20;				//地面的纵坐标，即小球运动的下界
	int top = 0;					//球运动的上界
	int left = 0;					//左边界
	int right = 40;					//右边界
	int v_x = 1;					//小球的x方向的速度
	int v_y = 1;					//小球的y方向的速度
	while (1)
	{
		x += v_x;					//移动小球位置
		y += v_y;
		system("cls");
		for (int i = 0; i < y; i++)			//绘制小球前的空行
			printf("\n");
		for (int i = 0; i < x; i++)
			printf(" ");
		printf("O\n");					//绘制小球
		if (y <= top || y >= bottom)
		{
			v_y = -v_y;
			Beep(1000, 2);
		}
		if (x <= left || x >= right)
		{
			v_x = -v_x;
			Beep(1000, 2);
		}
	}
	return 0;
}
