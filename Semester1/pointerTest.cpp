#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

void Output(const char** name, int size)
{
	for (int i = 0; i < size; ++i)
	{
		puts(*(name + i));
	}
}
int main()
{
	const char* name[] = { "gargoyle", "wraith", "troll", "dragon" };
	size_t sizeName = sizeof(name) / sizeof(name[0]);
	Output(name, sizeName);

	system("pause");
}