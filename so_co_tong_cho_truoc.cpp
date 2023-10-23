#include<stdio.h>
int n,m,sum=0;
int x[10000];
void In(){
	for (int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
int check(int i,int k){
	if (k==n) return(sum+i==m);
	return 1;
}
void Solution(int k){
	for (int i=1;i<=m-sum-(n-k);i++){
		if (check(i,k)){
			x[k]=i;
			sum+=i;
			if (k==n) In();
				else Solution(k+1);
			sum-=i;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	Solution(1);
}
