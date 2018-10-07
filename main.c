#include<stdio.h>
#include<stdlib.h>
int move(int x,int y)
{
	for(int i=0;i<=y;i++)
	{
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
	//while(1)
	{
		move(20,6);
	}
}
