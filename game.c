#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;

int array[4];



void scaninput(){
	printf("This is a game of 24 solver\nPlease input the 4 numbers you found in the deck\n");
	for(i=0;i<4;i++){
		scanf("%d",&array[i]);
	}
	printf("your four numbers are %d %d %d %d\n",array[0], array[1], array[2], array[3]);
	// add yes/no option with second input possibility
	// add check that all 4 numbers are in a deck.


}

int main(int argc, char *argv[]){ 

	scaninput();


}