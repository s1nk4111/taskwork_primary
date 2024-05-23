#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;
using Func = bool(*)(int);

void Output(int* data, int n, Func judge)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = *(data + i);
		if (judge(tmp))
			cout << tmp << " ";
	}
	cout << endl;
}
bool Judge1(int v)
{
	return v >= 3 && v <= 7;
}
bool Judge2(int v)
{
	if (v % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	int arr[10] = { 1, 4, 2, 5, 3, 6, 9, 7, 8, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Output(arr, n, Judge1);
	Output(arr, n, Judge2);

	system("pause");
}