#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j;

	for (j = 1; j <= 12; j++)
	{
		printf("%3d|", j);
	}
	printf("\n");

	for (j = 1; j <= 12; j++)
	{
		printf("---+");
	}
	printf("\n");

	for (i = 1; i <= 12; i++)
	{
		for (j = 1; j <= 12; j++)
		{
			printf("%3d|", j * i);
		}
		printf("\n");
	}

	system("pause");
}