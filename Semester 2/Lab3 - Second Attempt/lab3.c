/*
program: lab3.c
author: Muhammad, Khan
date: 2/2/21
purpose: Arrays
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 5

bool CheckNumbers(int m[], int z[])
{

	for (int b = 0; b < N; b++)
	{
		for (int c = 0; c < b; c++)
		{
				if (m[b] == z[b])
				{
					return true;
				}
				else
				{
					return false;
				}
		}
	}
}

int main()
{	
		int numbers[5];

		printf("> Enter 5 integers between 0 and 9:\n");

		for (int dracula = 0; dracula < 5; dracula++)
		{
			scanf("%d", &numbers[dracula]);
		}

		srand(time(0));
		int winners[5];

		printf("> The winning numbers were:\n");

		for (int count = 0; count < 5; count++)
		{
			winners[count] = rand() % 10;
			printf("%d, ", winners[count]);
		}

		printf("\b\b \n");

		int check;

		check = CheckNumbers(numbers, winners);
		if (check == true)
		{
			printf("> You won!!!");
		}
		else
		{
			printf("> Sorry, please try again.");
		}
	_getch();
}

