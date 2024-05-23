#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int* MakeArray(const int* arr, int w, int h)
{
	int* data = nullptr;
	data = (int*)malloc(sizeof(int) * w * h);
	for (int i = 0; i < w * h; ++i) {
		if (data != nullptr) {
			*(data + i) = *(arr + i);
		}
	}
	return data;
}
int main()
{
	int arr[2][5] =
	{
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 0 },
	};
	int* data = MakeArray(&arr[0][0], 5, 2);
	for (int i = 0; i < 10; ++i)
	{
		cout << *(data + i) << " ";
	}
	free(data);

	system("pause");
}