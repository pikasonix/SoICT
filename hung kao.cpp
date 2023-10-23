#include <stdio.h>
#include <string.h>
int n ; 
int x[11]={'-2','4','20','-15','0','6','9','-30','-10','10'};



int TRY(int i){
	for (int v=x[i-1]+1; v <= n-k+1){
		x[i]=v;
		if(i==k) Solution();
		else TRY
	}
	}




int main(){
	x[0]=0;
	scanf("%d",&n);
		
	}
	TRY(1);
}
