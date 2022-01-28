/*
program: lab1.c
author: Muhammad, Khan 
date: 1/14/2021
purpose: Decimal to Binary conversion and Recursive functions
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int mod(int a, int b);
void Convert2Binary(int c);

int main()
{
	int a, b;
	int binary;
	int convert;

	//Mod Function
	printf("Enter The Dividend : ");
	scanf("%d", &a);

	printf("Enter The Divisor : ");
	scanf("%d", &b);

	printf("Remainder: %d\n", mod(a, b));

	//Binary Conversion
	printf("Enter a number for conversion: ");
	scanf("%d", &binary);

	printf("The base 2 representation of %d is: ", binary);
	Convert2Binary(binary);
	printf("\n");

	//Must Include
	printf("The base 2 representation of 112 is: ");
	Convert2Binary(112);
	printf("\n");
	return 0;

	

}

int mod(int a, int b)
{
	int x, y, z;

	x = a / b;
	y = x * b;
	z = a - y;

	return z;

}
void Convert2Binary(int c)
{

	if (c == 0)
	{
		printf("0");
	}
	else if (c == 1)
	{
		printf("1");
	}
	else
	{
		 Convert2Binary(c / 2);
		 printf("%d", c % 2);
	}
}