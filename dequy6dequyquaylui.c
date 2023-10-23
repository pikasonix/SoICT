#include<stdio.h>
#define MAX 100
int n=4, x[MAX];
void printSolution(){
	int k=0;
	for( k =0 ; k < n; k++){
	
	printf("%d", x[k]);
	}
	printf("\n");
}
int try(int k){
	int v=0;
	for( v =0; v <= 1 ; v++){
		x[k] = v;
		if(k == n-1) printSolution();
		else try(k+1);
	
}
int main(){
	char str[4];
	
	try(0);
	return 0;
}
