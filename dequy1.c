#include<stdio.h>
int f(int n){
	if(n == 1)
	return 1;
	return n + f(n-1);
}
int main(){
	printf("%d\n", f(4));
}
