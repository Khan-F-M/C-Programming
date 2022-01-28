/*
Program: lab4.c
Author: Muhammad Khan
Date: 02/07/2021
Purpose: how to use strings in C and to sort strings in alphabetical order
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>


void sort_string(char names[][16], int rows);

main() {

	char names[][16] = { "Mike", "Timothy", "Katie", "Anna", "Jennifer", "Barbara" };
	int rows = sizeof(names) / sizeof(char[16]); 

	for (int a = 0; a < rows; a++) {

		printf("%s\n", names[a]);
	}

	sort_string(names, rows);
	
	printf("\nAlphabetically Sorted Names:\n");
	for (int i = 0; i < rows; i++)
	{
		printf("%s\n", names[i]);
	}
	_getch();
}

void sort_string(char names[][16], int rows) {

	char temp[16];

	for (int a = 0 ; a < rows - 1; a++) { 
		for (int b = a + 1; b < rows; b++) { 
			if (strcmp(names[a], names[b]) > 0) {
				strcpy(temp, names[a]);
				strcpy(names[a], names[b]);
				strcpy(names[b], temp);
			}
		}
   }
}
