/*
program: lab7.c
author: Muhammad Khan
date: 11/10/2020
purpose: using while/do-while loop
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int main()
{

	float min = 0, max = 0, avg = 0, sum = 0, num;
	int count = 0;

	printf("Please enter a floating point value. Enter zero to end the program:  ");
	scanf("%f", &num);

	while (num != 0)
	{
		if (num > 0)
		{
			if (count == 0)
			{
				max = num;
				min = num;
				sum = num;
				avg = num;
				count++;
			}
			else 
			{
				sum += num;
				avg = sum / (count + 1);
				count++;
			}
		}
		else
		{
			printf("Negative values are not allowed. ");
		}
			printf("Please enter another float (or zero to end the program): ");
			scanf("%f", &num);


			if (num >= max)
			{
				max = num;
			}
			if (num <= min && num > 0)
			{
				min = num;
			}
		

		
	}

	printf("> You entered a value of zero. Here are the outputs:");
	printf("\nEnteries: %d", count);
	printf("\nMaximum: %.2f", max);
	printf("\nMinimum: %.2f", min);
	printf("\nAverage: %.2f", avg);
	printf("\nSum: %.2f", sum);


	
	_getch();
	return 0;
}
	
