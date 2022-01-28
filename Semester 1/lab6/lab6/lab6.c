/*
Program: lab6.c
Author: Muhammad Khan
Date: Nov. 3, 2020
Purpose: for loops
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{


	float frn, cel;
	int dice;
	int sum = 0;

	printf("Table of Celsius and Fahrenheit degrees");
	printf("\nDegrees Celsius");
	printf("\t\tDegrees Fahrenheit");

	for(cel = 0.0; cel <= 100.0; cel += 20.0)
	{
		frn = 1.8 * cel + 32.0;
		printf("\n%.1lf", cel);
		printf("\t\t\t%.1lf", frn);
	}

	printf("\nEnter an Integer: ");
	scanf("%d", &dice);
	 
	for (int nezuko = 1;nezuko <= dice;)
	{
		if (nezuko % 2 != 0)
		{
			sum = sum + nezuko;
		}
		nezuko = nezuko + 1;
	}
	 
	printf("Sum of all odd numbers between 1 and %d is equal to: %d", dice, sum);

	_getch();
	return 0;
}