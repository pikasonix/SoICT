#include <stdio.h>
#include <string.h>
int n ; 
int a[11]={'-2','4','20','-15','0','6','9','-30','-10','10'};

void printfSolution(){
	for (int i = 1 ; i <= n ; i++){
		printf("%d ",x[i]);
	}
	printf("\n");
}

int TRY(int i){
	for(int v=1 ; v <=n ; v++){
		if(check[v]!=1){
			x[i]=v;
			check[v]=1;
			if(i==n) printfSolution();
			else TRY(i+1);
			check[v] =0;
		}
		
	}
	}




int main(){
	
		scanf("%d",&n);
		for(int i = 1; i<=n ; i++){
			check[i]=0;
		}
		TRY(1);
}
