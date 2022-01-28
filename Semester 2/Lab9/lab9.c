/*
Program: lab9.c
Date: 03/30/2021
Author: Khan, Muhammad
Purpose: File I/O and PPM Format
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main() {

	int row = 0, col = 0, numrows = 0, numcols = 0, max = 0;
	int rgb[3] = { 0, 0, 0 };
	char buffer[MAX];
	FILE* infile;
	FILE* outfile;

	infile = fopen("Ferrari.ppm", "r");

	if (infile == NULL)
	{
		printf("> Error opening input file. Program is terminating...\n");
		exit(0);
	}

	outfile = fopen("Ferrari_GS.ppm", "w");
	if (outfile == NULL)
	{
		printf("> Error opening output file. Program is terminating...\n");
		exit(0);
	}
	// Read the Magic number and display it on the console
	fgets(buffer, MAX, infile);
	printf("Version : %s", buffer);
	// Write "P3" to the output file using fprintf() for a PPM output image
	fprintf(outfile, "P3\n");

	// Read the comment and display it on the console
	fgets(buffer, MAX, infile);
	printf("Version : %s", buffer);
	// Write the same "buffer" to the output file using fputs()
	fputs(buffer, outfile);


	// Read the width and height, print both onto the console
	fscanf(infile, "%d", &numcols);
	fscanf(infile, "%d", &numrows); 
	printf("Columns %d and rows %d\n", numcols, numrows);
	// Write the same width and height values to the output file using fprintf()
	fprintf(outfile, "%d %d\n", numcols, numrows);

	// Read in the maximum grayscale shade and print onto the console
	fscanf(infile, "%d", &max);
	printf("Max: %d\n", max);
	// Write the same maximum color value to the output file using fprintf()
	fprintf(outfile, "%d\n", max);

	printf("\nProcessing Image...\n ");
	// Allocate a 2D array of integers named img dynamically based on the width and
	// height read from the input file
	int* img = (int*)malloc(row * col * sizeof(int));

	// In a two-level nested for-loop, read 3 integers from the input image, store them
	// in the elements of the rgb[] array. Then use the conversion formula to calculate
	// the grayscale color value using the individual elements of the rgb[] array and
	// store the converted grayscale color value in the 2D img array. Finally, write the
	// converted grayscale color from the img array to the output file
	for (row = 0; row < numrows; ++row) {
		for (col = 0; col < numcols; ++col)
		{
			fscanf(infile, "%d %d %d", rgb, rgb + 1, rgb + 2);
			*(img + row * numcols + col) = (0.3 * rgb[0]) + (0.59 * rgb[1]) + (0.11 * rgb[2]);
			fprintf(outfile, "%d %d %d\n",
				*(img + row * numcols + col), *(img + row * numcols + col), *(img + row * numcols + col));
		}
		fprintf(outfile, "\n");
	}
	
	// Release the previously allocated 2D array of integers img
	free(img);

	fclose(infile);
	fclose(outfile);

	return 0;
}
