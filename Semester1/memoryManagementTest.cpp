#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int main()
{
	int arraySize;
	cout << "何バイト確保しますか？";
	cin.width(6);
	cin >> arraySize;
	if (arraySize > 1000000)
	{
		return 0;
	}
	char* p = nullptr;
	p = (char*)malloc(sizeof(char) * arraySize);

	for (int i = 0; i < arraySize; ++i)
	{
		if (p != nullptr)
		{
			cin >> *(p + i);
		}
	}
	char* pTmp = (char*)malloc(sizeof(char) * arraySize);
	memcpy(pTmp, p, sizeof(char) * arraySize);
	free(p);
	p = pTmp;
	for (int i = 0; i < arraySize; ++i)
	{
		if (p != nullptr)
		{
			cout << *(p + i);
		}
	}
	cout << endl;
	free(p);

	system("pause");
}