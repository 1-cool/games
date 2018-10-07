#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

int move(int x,int y)

{

	for(int i=0;i<=y;i++)	{

		printf("\n");

	}

	for(int i=0;i<x;i++)

	{

		printf(" ");

	}

	printf("   *\n");

	for(int i=0;i<x;i++)

	{

		printf(" ");

	}

	printf(" *****\n");

	for(int i=0;i<x;i++)

	{

		printf(" ");

	}

	printf("  * *\n");

}

int main()

{

	int x=25,y=6,input;

	while(1)

	{

		system("cls");

		move(x,y);

		if(kbhit())

		{

			input=getch();

			if(input=='w')

			{

				y--;

			}

			if(input=='a')

			{

				x--;

			}

			if(input=='s')

			{

				y++;

			}

			if(input=='d')

			{

				x++;

			}

		}

	}

}
