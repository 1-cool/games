#include<stdio.h>
#include<windows.h>
#define X 25			//球的初始横坐标
#define Y 10			//球的初始纵坐标
int main()
{
	int x = X, y = Y;
	int	limlower = 10;				//地面的纵坐标，即小球运动的下界
	int limup = x / 5;				//球运动的上界
	for (; limup <= limlower; limup += limup/5)			//小球的运动的最高点减小，直到与地面相等
	{

		for (; y < limlower; y++)			//控制球下降
		{
			system("cls");
			for (int i = 0; i < y; i++)
				printf("\n");
			for (int i = 0; i < x; i++)
				printf(" ");
			printf("O\n");
			Sleep(5);
		}

		for (; y > limup; y--)				//控制球上升
		{
			system("cls");
			for (int i = 0; i < y; i++)
				printf("\n");
			for (int i = 0; i < x; i++)
				printf(" ");
			printf("O\n");
			Sleep(5);
		}
	}
}
