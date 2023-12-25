#include<stdio.h>
#include<string.h>
int n;
int len;
int a[20];
char s[6];
void Inso(){
	for (int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}

int check(int k,int i){
    if (k<len) return 1;
    for (int j=0;j<len;j++){
        char s1=a[k-len+1+j]+'0';
        if(s[j]!=s1) return 1;
    }
    return 0;
}
void TRY(int k){
	for(int i=0;i<2;i++){
		if (check(k,i)){
			a[k]=i;
			if (k==n-1) Inso();
				else TRY(k+1);
		}
	}
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    len=strlen(s);
    TRY(0);
}

