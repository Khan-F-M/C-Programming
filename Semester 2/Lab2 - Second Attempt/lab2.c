/*
program: lab2.c
author: Muhammad, Khan
date: 1/23/2021
purpose: Understaning Bitwise Operators
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long int NextPowerOfTwo(unsigned long int x)
{
	unsigned long int  Rpwr = 1;

	while (Rpwr <= x)
	{
		Rpwr = Rpwr << 1;
	}

	return  Rpwr;
}
unsigned long int WhichPowerOfTwo(unsigned long int y)
{
	unsigned long int Divd = NextPowerOfTwo(y);
	int count = 0;

	while (Divd > 2)
	{
		
		Divd = Divd >> 1;
		count++;
	}

	return count;
}


int main()
{
	unsigned long int a = NextPowerOfTwo(165002446);
	printf("The first power of 2 above 165002446 is: %ld\n", a);

	int n = WhichPowerOfTwo(a);
	printf("%ld is 2 to the power of %d\n", a, n);


	return 0;
}

