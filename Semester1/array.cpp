#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

void InputArray(int (*p)[5])
{ 
	for (int i = 0; i < 3 * 5; ++i) {
		(void)scanf("%d", i);
	}
}

void OutputArray(const int* const p)
{
	for (int i = 0; i < 3 * 5; ++i) {
		printf("%d ", *(p + i));
	}
}

int main()
{
	int v[3][5];
	InputArray(v);
	OutputArray(&v[0][0]);

	system("pause");
}