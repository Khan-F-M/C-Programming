
/*

Program: lab7.c

Date: 03/12/2021

Author: Khan, Muhammad

Purpose: Complex Number Addtion and Multiplication using Pointers and Functions

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void complex_multi(double* a, double* b, double* c) {

	double temp[2];

	temp[0] = (a[0] * b[0]) - (a[1] * b[1]);

	temp[1] = (a[0] * b[1]) + (a[1] * b[0]);

	c[0] = temp[0];

	c[1] = temp[1];

}

void complex_add(double* a, double* b, double* c)

{

	c[0] = a[0] + b[0];

	c[1] = a[1] + b[1];

}

double len_square(double* a)

{

	double r;

	r = (a[0] * a[0] + a[1] * a[1]);

	return r;

}

int main() {

	double z[2] = { 0.0, 0.0 };

	double c[2] = { 0.4, 0.25 };

	int maxIter = 1000;

	int iter = 0;

	while (iter < maxIter)

	{

		complex_multi(z, z, z);

		complex_add(z, c, z);

		printf("%lf", len_square(z));

		if (len_square(z) > 4.0)

		{

			break;

		}

		else {

			iter = iter + 1;

		}

	}

	printf("\nNumber of iterations = %d", iter);

}