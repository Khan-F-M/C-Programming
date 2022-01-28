/*
Program: lab6.c
Author: Muhammad Khan
Date: 03/08/2021
Purpose: Working with pointers and 3-D Arrays
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int frar[2][3][4] = { {{7,2,1,13},{0,3,9,12},{5,6,2,21}}, {{1,41,83,3},{15,99,43,5},{9,11,8,7} } };
	int(*ptr)[3][4];
	ptr = frar;

	for (int a = 0; a < 1; a++)
	{
		for (int b = 0; b < 6; b++)
		{
			for (int c = 0; c < 4; c++)
			{
				printf("%d  ", (*(*(*(ptr + a) + b) + c)));
			}
			printf("\n");
		}
	}

	printf("\n\n");

	int frarTwo[2][3][2];
	int(*Aptr)[3][2] = frarTwo;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				Aptr = (i + 1) * (i + 1) + (j + 1) * (j + 1) + (k + 1) * (k + 1);
				printf("%d ", Aptr);
			}
			printf("\n");
		}
	}
	return 0;

}