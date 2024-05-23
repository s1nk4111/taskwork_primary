#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Output(int(&a)[4][4])
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			printf("%3d", a[y][x]);
		}
		puts("");
	}
}
void RotateLeft(int(&out)[4][4], const int(&in)[4][4])
{
	for (int y = 0; y < 4; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			out[x][y] = in[y][4 - 1 - x];
		}
	}
}
int main()
{
	int a[4][4] =
	{
	  { 0, 1, 2, 3 },
	  { 4, 5, 6, 7 },
	  { 8, 9, 10, 11 },
	  { 12, 13, 14, 15 }
	};
	int b[4][4] = {};
	Output(a);
	puts("== Rotate left ==");
	RotateLeft(b, a);
	Output(b);

	system("pause");
	return 0;
}