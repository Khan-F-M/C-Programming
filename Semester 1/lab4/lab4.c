#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{

	double income;
	double tax;

	printf("Please enter your annual income in number format: \n");
	scanf("%lf", &income);

	if (income >= 0 && income <= 45000)
	{
		tax = income * 0.15;
		printf("\nYour income tax will be $%.2lf\n\n", tax);
	}
	else
	{
		if (income >= 45001 && income <= 90000)
		{
			tax = 6750 + 0.20 * (income - 45000);
			printf("\nYour income tax will be $%.2lf\n\n", tax);
		}
		if (income >= 90001 && income <= 140000)
		{
			tax = 15750 + 0.26 * (income - 90000);
			printf("\nYour income tax will be $%.2lf\n\n", tax);
		}
		if (income >= 140001 && income <= 200000)
		{ 
			tax = 28750 + 0.29 * (income - 140000);
			printf("\nYour income tax will be $%.2lf\n\n", tax);
		}
		if (income > 200000)
		{
			tax = 46150 + 0.33 * (income - 200000);
			printf("\nYour income tax will be $%.2lf\n\n", tax);
		}

	}
	
	_getch();
	return 0;
}