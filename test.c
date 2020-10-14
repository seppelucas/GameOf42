#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "safeMalloc.h"

/* A recursive factorial function */
int factorial(int n) {
	if (n == 1) {
		return n;
	}
	return n * factorial(n - 1);
}

/* Handles the input */
void scanInput(int *array){
	char yn = 'n';
	while (yn != 'y' && yn != 'Y') {
		printf("Please input 4 numbers drawn from a deck:\n");
		for (int i = 0; i < 4; i++) {
			scanf("%i", &array[i]);
		}
		printf("Are these numbers correct?\nY / N\n");
		scanf("\n");
		scanf("%c", &yn);
		if (yn == 'y' || yn == 'Y') {
			printf("Starting solving process.\n");
		} else {
			printf("Please try again.\n");
		}
	}
}

/* Returns the result of an arithemtic operator, based on an input.
Used best with a loop */
int doOperation(int a, int b, int op) {
	int result = -1;
	switch(op) {
		case 0:
			result = a + b;
			break;
		case 1:
			result = a - b;
			break;
		case 2:
			result = (a > 0 && b > 0 ? a * b : -1);
			break;
		case 3:
			result = (b > 0 ? a / b : -1);
			break;
	}
	return result;
}

/* Swap to values in an array */
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Reverses the order of values in an array */
void reverseArray(int *array, int length) {
	for (int i = 0; i < length / 2; i++) {
		swap(&array[i], &array[length - 1 - i]);
	}
}

/* Goes to the next permutation in an array, based on the iterator of a loop.
There are length! permutations of an array */
void nextConfiguration(int *array, int length, int i) {
	/* There are length * 2 steps in this algorithm before the pattern repeats itself */
	int fullCircle = length * 2;
	/* Every uneven step is to reverse */
	if (i % 2 == 1) {
		reverseArray(array, 4);
	} else {
	/* And every even step is to swap some numbers. First 0 and 1, then 1 and 2, then 2 and 3, and so on.
	Until the last one has been reached, then you swap it with 0. */
		i %= fullCircle;
		if (i / 2 + 1 == length) {
			swap(&array[i / 2], &array[0]);
		} else {
			swap(&array[i / 2], &array[i / 2 + 1]);
		}
	}
}

/* Prints an array of length */
void printArray(int *array, int length) {
	printf("{");
	int first = 1;
	for (int i = 0; i < length; i++) {
		if (!first) {
			printf(", ");
		}
		printf("%i", array[i]);
		first = 0;
	}
	printf("}\n");
}

void solve(int *array) {
	
}

int main(int argc, char *argv[]){
	int length = 4;
	int *input = safeMalloc(length * sizeof(int)); 
	scanInput(input);
	int permutations = factorial(length) * 2;
	for (int i = 0; i < permutations; i++) {
		nextConfiguration(input, 4, i);
		printArray(input, 4);
		solve(input);
	}
	free(input);
}
