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

	// add yes/no option with second input possibility
	char ch;
	scanf("%c\n",&ch);
	scanf("%c",&ch);

	if(ch == 'n'){

		printf("\nPlease try again\n");
		scaninput();
	}
	






	// add check that all 4 numbers are in a deck.


}

int main(int argc, char *argv[]){ 

	scaninput();


}