#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DS{
    char name[10];
    char email[50];
}DS;
DS SV[10000];

void quickSort(DS SV[],int l, int r){
    int i=l, j=r;
    char x[10];
    strcpy(x,SV[(l+r)/2].name);
    while (i<=j){
        while (strcpy(SV[i].name,x)<0) i++;
        while (strcpy(SV[j].name,x)>=0) j--;
        if (i<=j){
            DS temp=SV[i];
            SV[i]=SV[j];
            SV[j]=temp;
            i++; j--;
        }
    }
    if (l<j) quickSort(SV,l,j);
    if (i<r) quickSort(SV,i,r);
}

int binarySearch(DS SV[], int l, int r, char x[]){
	if (r>=l){
		int mid = l+(r-l)/2;
		if (strcpy(SV[mid].name,x)==0) return mid;
		if (strcpy(SV[mid].name,x)> 0)
			return binarySearch(SV,l,mid-1,x);
		return binarySearch(SV,mid+1,r,x);
	}
	return -1;
}

int main(){
    int n;
    char cmd[10];

    while(1){
        scanf("%s",cmd);
        if (strcmp(cmd,"Quit")) {printf("Bye"); break;}
        if (strcmp(cmd,"Load")){
            scanf("%d",&n);
            for (int i=0;i<n;i++) scanf("%s %s",&SV[i].name,&SV[i].email);
            quickSort(SV,0,n-1);
        }
        if (strcmp(cmd,"Find")) {
            char s[10];
            scanf("%s",s);
            printf("%s\n",SV[binarySearch(SV,0,n-1,s)].email);    
        }
        if (strcmp(cmd,"Insert")) {
            scanf("%s %s",&SV[n].name,&SV[n].email); 
            n++;
            quickSort(SV,0,n-1);
        }

        if (strcmp(cmd,"Remove")) {
            char s[10];
            scanf("%s",s);
            int k = binarySearch(SV,0,n-1,s); 
            if (k!=-1){
                for(int i=k+1;i<n;i++) SV[i-1]=SV[i];
                n--;
            }
        }
        if (strcmp(cmd,"Store")) {
            char s[20];
            scanf("%s",s);
            FILE *f=fopen(s,"w");
            
        }
    }
    
}