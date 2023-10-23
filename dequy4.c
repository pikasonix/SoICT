#include<stdio.h>
#define MAX 100
int M[MAX][MAX];
int C(int k, int n){
	if( k == 0 || n == k) M[k][n] = 1;
	else if (M[k][n] == 0)
	M[k][n]= C(k,n-1) + C(k-1,n-1);
	return M[k][n];
}
int main(){
	memset(M,0,sizeof(M));
	printf("%d", C(3,7));
}

