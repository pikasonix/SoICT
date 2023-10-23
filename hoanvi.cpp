#include<stdio.h>
int m[100000]={0};
int x[100000];
int n;
void In(){
	for (int i=1;i<=n;i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}
void hoanvi(int k){
	for (int i=1;i<=n;i++){
		if (m[i]==0){
			x[k]=i;
			m[i]=1;
			if (k == n) In();
				else hoanvi(k+1);
		m[i]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	hoanvi(1);
}
