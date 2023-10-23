#include<stdio.h>
int n;
int a[20];
void Inso(){
	for (int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void Nhiphan(int k){
	for (int i=0;i<2;i++){
		if (a[k-1]+i<2){
			a[k]=i;
			if (k==n-1) Inso();
				else Nhiphan(k+1);	
			}
	}
}
int main(){
	scanf("%d",&n);
	Nhiphan(0);
}



