#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

int input[4];

void scanInput(){
	//Input with confirmation
	char yn = 'n';
	while (yn != 'y') {
		printf("Please input 4 numbers drawn from a deck:\n");
		for (int i = 0; i < 4; i++) {
			scanf("%i", &input[i]);
		}
		printf("Are these numbers correct?\nY / N\n");
		scanf("\n");
		scanf("%c", &yn);
		if (yn == 'y') {
			printf("Starting solving process.\n");
		} else {
			printf("Please try again.\n");
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
		else{
			return  0;
		}
	//}
}

void solvegame(int input[4]){

	int k=0,l=0,o=0, scanning =1;

	while(scanning){
		if(24 == options2(options2(input[0],input[1],l),options2(input[2],input[3],o),k) ){ // (a b)(c d)
			printf("yes\n");
			scanning =0;
		}
		if(24 == options2(   options2(options2(input[0],input[1],o),input[2],l) ,input[3],k)){// ((a b)c)d)
			printf("yes2\n");
			scanning =0;
		}
		if(24 == options2(input[0],options2(options2(input[1],input[2],o),input[3],l),k)){ // (a((b c)d))
			printf("yes3\n");
			scanning =0;			
		}
		if(24 == options2(input[0],options2(input[1], options2(input[2],input[3],o),l),k)){ // (a(b(c d)))
			printf("yes4\n");
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
	scanInput();
}
