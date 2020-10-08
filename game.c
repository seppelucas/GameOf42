#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int array[4];
// seppe test



void scaninput(){
	printf("This is a game of 24 solver\nPlease input the 4 numbers you found in the deck\n");
	for(int i=0;i<4;i++){
		scanf("%d",&array[i]);
	}
	printf("your four numbers are: %d %d %d %d\nIs this correct? (y/n)",array[0], array[1], array[2], array[3]);

// confirm if the input is right
	char ch;
	scanf("%c\n",&ch);
	scanf("%c",&ch);

	if(ch == 'n'){

		printf("\nPlease try again\n");
		scaninput();
	}
// check if the numbers are in the given range

	for(int i=0;i<4;i++){
		if(array[i] >12 || array[i] <= 0){
			printf("\nplease input numbers in correct range and try again\n");
			scaninput();
		}
	}

}

int main(int argc, char *argv[]){ 

	scaninput();


}