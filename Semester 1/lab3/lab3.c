#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <math.h>


int main()
{
	float v = 7700.0;
	double c = 299792458.0;
	double gamma;
	float seconds;

	int Dy;

	printf("Please enter the number of days spent on ISS: ");
	scanf("%d", &Dy);

	gamma = 1.0 / sqrt(1 - (pow(v, 2)) / (pow(c, 2)));

	seconds = (gamma - 1.0) * Dy * 24 * 60 * 60;

	printf("\n\n\nYour twin sister is %.2f seconds older than you!", seconds);

	_getch();
	return 0;

}