#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

int input[4];
int originalinput[4];
int intshuffle =0;
int i=0,j=0;
int cnt;

void scanInput(){
	//Input with confirmation
	char yn = 'n';
	while (yn != 'y' && yn != 'Y') {
		printf("Please input 4 numbers drawn from a deck:\n");
		for (int i = 0; i < 4; i++) {
			scanf("%i", &input[i]);
			originalinput[i] = input[i];
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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void randomize(int arr[], int n) {
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
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
			if(b == 0){
				return 0;
			}
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

char getOperatorChar(int a){
	if(a == 0){
		return '+';
	}
	if(a == 1){
		return '-';
	}
	if(a == 2){
		return '/';
	}
	if(a == 3){
		return 'x';
	}
	return '\0';
}

void solvegame(int input[4]){

	int k=0,l=0,o=0, scanning =1;

	while(scanning){
		if(24 == options2(options2(input[0],input[1],l),options2(input[2],input[3],o),k) ){ // (a b)(c d)
			printf("(%d%c%d)%c(%d%c%d)\n",input[0],getOperatorChar(l),input[1],getOperatorChar(k), input[2],getOperatorChar(o),input[3]);
			scanning =0;
		}
		if(24 == options2( options2(options2(input[0],input[1],o),input[2],l) ,input[3],k)){// ((a b)c)d)
			scanning =0;
			printf("(((%d%c%d)%c%d)%c%d)\n",input[0],getOperatorChar(o),input[1],getOperatorChar(l),input[2],getOperatorChar(k),input[3]);
		}
		if(24 == options2(input[0],options2(options2(input[1],input[2],o),input[3],l),k)){ // (a((b c)d))
			scanning =0;
			printf("%d%c((%d%c%d)%c%d)\n",input[0],getOperatorChar(k),input[1],getOperatorChar(l),input[2],getOperatorChar(o),input[3]);		
		}
		if(24 == options2(input[0],options2(input[1], options2(input[2],input[3],o),l),k)){ // (a(b(c d)))
			scanning =0;
			printf("(%d%c(%d%c(%d%c%d)))\n",input[0],getOperatorChar(k) , input[1],getOperatorChar(l),input[2],getOperatorChar(o),input[3]);	
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
						randomize(input,3);
						solvegame(input);
						scanning =0;
					}
				}
			}
		}	
	}
}

int main(int argc, char *argv[]){ 
	scanInput();
	solvegame(input);
}
