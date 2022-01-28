/*
Program: lab8.c
Date: 03/21/2021
Author: Khan, Muhammad
Purpose: Complex Number Addtion and Multiplication using typedef function
*/
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
	double real;
	double imag;
} Complex;

Complex complex_mult(Complex* a, Complex* b);
Complex complex_add(Complex* a, Complex* b);
double len_square(Complex* a);
 
int main() {

	Complex z = { 0.0, 0.0 };
	Complex c = { 0.38, 0.25 };

	int maxIter = 765;
	int iter = 0, counter = 0, color = 0;
	int rgb[3] = { 0, 0, 0 };

	while (iter < maxIter)
	{
		z = complex_mult(&z, &z);
		z = complex_add(&z, &c);
		printf("%lf\n", len_square(&z));

		if (len_square(&z) > 4.0)
			break;
		else
			iter = iter + 1;
	}

	printf("\n\nNumber of iterations = %d\n", iter);

	color = iter;

	for (int i = 0; i <= 7 && counter <= color; i++)
	{
		for (int j = 0; j <= 7 && counter <= color; j++)
		{
			for (int k = 0; k <= 7 && counter <= color; k++)
	
			{
				counter++;
				rgb[0] = i;
				rgb[1] = j;
				rgb[2] = k;

				printf("%d corresponds to RGB combination %d, %d, %d\n", color, rgb[0], rgb[1], rgb[2]);
			}
		}
	}
	_getch();
}

Complex complex_mult(Complex* a, Complex* b)
{
	Complex temp;
	temp.real = (a->real * b->real) - (a->imag * b->imag);
	temp.imag = (a->real * b->imag) + (a->imag * b->real);
	return temp;


};

Complex complex_add(Complex* a, Complex* b)
{
	Complex temp2;
	temp2.real = a->real + b->real;
	temp2.imag = a->imag + b->imag;
	return temp2;
};

double len_square(Complex* a)
{
	double r;
	r = a->real * a->real + a->imag * a->imag;
	return r;
}