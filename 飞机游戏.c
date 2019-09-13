#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
int x, y;				//飞机位置
int bullet[35];			//子弹位置
int enemy[35];			//敌机位置
int higt, widht;		//游戏画面尺寸
int score;				//得分
int hard;				//游戏难度
bool game;				//游戏状态
void HideCursor()				//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x, int y)		//类似于清屏函数，光标移动到原点位置进行重画
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void startup()					//数据初始化
{
	higt = 20; widht = 30;		//设置画面尺寸
	x = widht / 2; y = higt / 5 * 4;	//飞机初始位置
	memset(enemy, -1, sizeof(enemy));	//敌机初始位置
	enemy[rand() % widht] = 0;
	score = 0;					//初始化分数
	hard = 0;					//初始化游戏难度
	game = 1;					//初始化游戏状态
	for (int t = 0; t < widht; ++t)
		bullet[t] = -2;//初始化子弹位置
}
void draw()						//绘制
{
	gotoxy(0, 0);
	for (int i = 0; i < higt; ++i)
	{
		for (int j = 0; j < widht; ++j)
		{
			if (i == y && j >= x - 2 && j <= x + 2 || i == y - 1 && j == x || i == y + 1 && j == x - 1 || i == y + 1 && j == x + 1)
				printf("*");						//绘制飞机
			else if (enemy[j] == i)
				printf("#");						//绘制敌机
			else if (bullet[j] == i)
				printf("|");						//绘制子弹
			else
				printf(" ");

		}
		printf("|\n");
	}
	for (int i = 0; i < widht; ++i)
		printf("-");
	printf("+\n得分：%d\n", score);
}
void update_without_input()
{
	if (enemy[x] == y)
	{
		game = 0;
	}
	for (int t = 0; t < widht; ++t)
		if (bullet[t] == enemy[t])		//子弹击中敌机
		{
			++score;						//增加得分
			Beep(10000, 2);
			bullet[t] = -2;				//子弹无效
			enemy[t] = -1;
			enemy[rand() % widht] = 0;	//产生新敌机
		}
	for (int t = 0; t < widht; ++t)
		if (bullet[t] > 0)					//移动子弹
			--bullet[t];
		else								//子弹飞出画面
			bullet[t] = -2;
	/*用来控制敌机向下移动的速度。每隔几次循环，才移动一次敌机
	这样修改的话，用户按键交互速度还是保持很快，但我们NPC的移动显示可以降速*/
	static int speed = 0;
	if (speed < 15)
		++speed;
	else
	{
		for (int t = 0; t < widht; ++t)
			if (enemy[t] >= 0)

				++enemy[t];
		speed = 0;
	}
	for (int t = 0; t < widht; ++t)
		if (enemy[t] > higt)					//如果敌机跑出画面
		{
			enemy[t] = -1;
			enemy[rand() % widht] = 0;
		}
	if (score - 10 >= hard)
	{
		hard = score;
		enemy[rand() % widht] = 0;
	}
}
void update_with_input()
{
	char input;
	if (_kbhit())				// 判断是否有输入,VS中不允许使用kbhit，这里使用_kbhit代替
	{
		input = _getch();		//VS中不允许使用getch，这里使用_getch代替
		if (input == 'w' && y > 0)		//飞机上移
			y--;
		if (input == 'a' && x > 0)		//飞机左移
			x--;
		if (input == 's' && y < higt - 1)		//飞机下移
			y++;
		if (input == 'd' && x < widht - 1)		//飞机右移
			x++;
		if (input == ' ' && bullet[x] == -2)		//飞机发射子弹
			bullet[x] = y - 2;
	}
}
void gameover(int temp)
{
	if (temp)
		return;
	gotoxy(0, 0);
	printf("Game Over!!!!\nPress Enter to Restart the Game");//提示游戏结束
	while (_getch() != 13);	//回车重新开始游戏
	startup();				//数据初始化
	system("cls");			//清屏
}
int main()
{
	HideCursor();			//隐藏光标
	startup();				//数据初始化
	srand(time(NULL));		//初始化随机数种子
	while (1)
	{
		draw();				//绘制
		update_without_input();				//更新与用户无关的内容
		update_with_input();				//更新与用户有关的内容
		gameover(game);					//判定游戏状态
	}
	return 0;
}
