#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void scanInput(int *array){
	//Input with confirmation
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

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverseArray(int *array, int size) {
	for (int i = 0; i < size / 2; i++) {
		swap(&array[i], &array[size - 1 - i]);
	}
}

void nextConfiguration(int *array, int length, int i) {
	int fullCircle = length * 2;
	if (i % 2 == 1) {
		reverseArray(array, 4);
	} else {
		i %= fullCircle;
		if (i / 2 + 1 == length) {
			swap(&array[i / 2], &array[0]);
		} else {
			swap(&array[i / 2], &array[i / 2 + 1]);
		}
	}
}

void displayArray(int *array, int size) {
	printf("{");
	int first = 1;
	for (int i = 0; i < size; i++) {
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
	int input[4]; 
	scanInput(input);
	for (int i = 0; i < 24; i++) {
		nextConfiguration(input, 4, i);
		displayArray(input, 4);
		solve(input);
	}
}
