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

int options2(int a, int b, int i2){

	//for(;i2<4;i2++){
		if(i2 ==0){
			return a+b;
		}
		if(i2 ==1){
			return a-b;
		}
		if(i2 ==2){
			return a/b;
		}
		if(i2 ==3){
			return a*b;
		}
	//}
}

void solvegame(int array[4]){

	int total =0;
	int k=0,l=0,o=0, scanning =1;

	while(scanning){
		if(24 == options2(options2(array[0],array[1],l),options2(array[2],array[3],o),k) ){
			printf("yes\n");
			scanning =0;
		}
		if(24 == options2(   options2(options2(array[0],array[1],o),array[2],l) ,array[3],k)){
			printf("yes2\n");
			scanning =0;
		}
		if(24 == options2(array[0],options2(options2(array[1],array[2],o),array[3],l),k)){
			printf("yes3\n");
			scanning =0;			
		}
		else{
			k++;
			if(k == 4){
				l++;
				k=0;
				if(l ==4 ){
					o++;
					l=0;
					if(o ==4){
						printf("no solution for now");
						scanning =0;
					}
				}
			}
		}

		printf("k=%d l=%d o=%d\n",k,l,o);
			
	}
	}








int main(int argc, char *argv[]){ 

	scaninput();

	// four operators + - * / 
	solvegame(array);


}