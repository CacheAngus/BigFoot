/*
 ============================================================================
 Name        : Lab 1
 Author      : Cache Angus 20000629
 Description : CMPE 365 Lab 1
 ============================================================================
*/

#include <stdio.h>


int i;
int l;

int collatz_alone(unsigned int n){ //simply the collatz program
	int count = 0;
	while(n!= 1){
		if (n %2 == 0){
			n/=2;
			count +=1;}
		else { n = 3*n+1;
		count += 1;}
		}
		printf("%d \n", count);
		return 1;
}

int collatz_markedD(unsigned int n){ //for decrementation
	int count = 0;
	int m = n; //storing the initial input value
		while(n!= 1){
			if (n > m){ //check initially if the value has already been tested
				n=1;
			}
			else {
			if (n %2 == 0){
				n/=2;
				count +=1;}
			else {
				n = 3*n+1;
				count += 1;
				}
			}
			}
			printf("%d \n", count);
			return 1;
	}

int collatz_marked(unsigned int n){ //for incrementing
	int count = 0;
	int m = n; //storing the initial input value
		while(n!= 1){
			if (n < m){ //check initially if the value has already been tested
				n=1; //if it has, then break out
			}
			else { //else run the collatz
			if (n %2 == 0){
				n/=2;
				count +=1;}
			else {
				n = 3*n+1;
				count += 1;
				}
			}
			}
			printf("%d \n", count); //print out how many times it had to increment
			return 1;
	}

int main(void){

	for(i = 1000; i >0; i--){
		 l= collatz_markedD(i);//decrement
		}
	for(i = 1; i <= 1000; i++){
		l = collatz_marked(i);//increment
	}

return 0;
}
