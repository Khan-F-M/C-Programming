/*
program: lab5.c
author: Muhammad, Khan date: 10/13/2020
purpose: using switch-case statement
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{
	int choice;
	float input;
	float output;

	printf("Please pick a conversion option from below:\n");
	printf("> (1)Seconds to Minutes\n");
	printf("> (2)Minutes to Hours\n");
	printf("> (3)Hours to Days\n");
	scanf("%d", &choice);
	
	switch (choice)
	{
	case 1:
		printf("Please enter the amount of seconds:\n");
		scanf("%f", &input);
		output = input / 60.0;
		if (output > 1.0)
			printf("%.2f Seconds is %.2f Minutes.", input, output);
		else
			printf("%.2f Seconds is %.2f Minute.", input, output);
		break;
	case 2:
		printf("Please enter the amount of minutes:\n");
		scanf("%f", &input);
		output = input / 60.0;
		if (output > 1.0)
			printf("%.2f Minutes is %.2f Hours.", input, output);
		else
			printf("%.2f Minutes is %.2f Hour.", input, output);
		break;
	case 3:
		printf("Please enter the amount of hours:\n");
		scanf("%f", &input);
		output = input / 24.0;
		if (output > 1.0)
			printf("%.2f Hours is %.2f Days.", input, output);
		else
			printf("%.2f Minutes is %.2f Day.", input, output);
		break;
	default:
		printf("The option you have selected is not available. Please rerun the program.\n");
		break;
	}
	_getch();
	return 0;
}