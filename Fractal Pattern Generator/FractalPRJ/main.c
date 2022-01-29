#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
	double real;
	double imag;
} Complex;

typedef struct Pixel {
	int Red;
	int Green;
	int Blue;
} Pixel;

Complex complex_mult(Complex* a, Complex* b) {
	Complex temp;
	temp.real = (a->real * b->real) - (a->imag * b->imag);
	temp.imag = (a->real * b->imag) + (a->imag * b->real);
	return temp;
};

Complex complex_add(Complex* a, Complex* b) {
	Complex temp2;
	temp2.real = a->real + b->real;
	temp2.imag = a->imag + b->imag;
	return temp2;
};

double len_square(Complex* a) {
	double r;
	r = a->real * a->real + a->imag * a->imag;
	return r;
}

int fractal(Complex* z, Complex* c, int maxIter) {

	int iter = 0;

	while (iter < maxIter) {

		(*z) = complex_mult(z, z);
		(*z) = complex_add(z, c);

		if (len_square(z) > 4.0) {
			break;
		}
		else {
			iter = iter + 1;
		}
	}

	return iter;
}

Pixel convert(int color) {

	int counter = 0;
	Pixel rgb;

	for (int i = 0; i <= 7 && counter <= color; i++)
	{
		for (int j = 0; j <= 7 && counter <= color; j++)
		{
			for (int k = 0; k <= 7 && counter <= color; k++)

			{
				counter++;
				rgb.Red = i;
				rgb.Green = j;
				rgb.Blue = k;
			}
		}
	}

	return rgb;
}


int main() {

	int cols, rows;
	int max = 7;
	FILE* infile;
	FILE* infile2;
	int color;
	Complex z, c;
	Pixel rgb;

	printf("Enter Image Width: ");
	scanf("%d", &rows);

	printf("Enter Image Height: ");
	scanf("%d", &cols);

	infile = fopen("mandelbrot.ppm", "w");
	infile2 = fopen("julia.ppm", "w");

	if (infile == NULL)
	{
		printf("> Error opening file. Program is terminating...\n");
		exit(0);
	}

	if (infile2 == NULL)
	{
		printf("> Error opening file. Program is terminating...\n");
		exit(0);
	}

	//Write the Magic number
	fputs("P3\n", infile);
	fputs("P3\n", infile2);

	// Write the comment to the output file using fputs()
	fputs("#This is a comment\n", infile);
	fputs("#This is a comment\n", infile2);

	//Write the width and height values to the output file using fprintf()
	fprintf(infile, "%d %d\n", cols, rows);
	fprintf(infile2, "%d %d\n", cols, rows);

	// Write the maximum color value to the output file using fprintf()
	fprintf(infile, "%d\n", max);
	fprintf(infile2, "%d\n", max);

	printf("\nProcessing Image...\n");

	// Allocate a 2D array of integers named img dynamically based on the width and height read from the input file
	int* img = malloc((rows * cols) * sizeof(int));

	double step_height = 4.0 / cols;
	double step_width = 4.0 / rows;
	int maxIter = 512;

	printf("Generating Mandelbrot Fractal Pattern...");

	for (double j = 0; j < cols; j++)
	{
		for (double k = 0; k < rows; k++)
		{
			z.real = 0;
			z.imag = 0;
			c.real = ((j * step_height) - 2.0);
			c.imag = ((k * step_width) - 2.0);
			color = fractal(&z, &c, maxIter);
			rgb = convert(color);
			fprintf(infile, "%d %d %d\n", rgb.Red, rgb.Green, rgb.Blue);
		}
		fprintf(infile, "\n");
	}

	printf("\nGenerating Julia Fractal Pattern...\n\n");

	for (double j = 0; j < cols; j++)
	{
		for (double k = 0; k < rows; k++)
		{
			z.real = ((j * step_height) - 2.0);
			z.imag = ((k * step_width) - 2.0);
			c.real = -0.8;
			c.imag = 0.156;
			color = fractal(&z, &c, maxIter);
			rgb = convert(color);
			fprintf(infile2, "%d %d %d\n", rgb.Red, rgb.Green, rgb.Blue);
		}
		fprintf(infile2, "\n");
	}

	//free the allocated memory for the image
	free(img);

	fclose(infile);
	fclose(infile2);

	return 0;
}
