#include<stdio.h>
int f(int n){
	if ( n <=1) return 1;
	return f(n-1) + f(n-2); 
}
int main(){
	for(int i = 0; i<= 10; i++)
	printf("%d " , f(i));
}
