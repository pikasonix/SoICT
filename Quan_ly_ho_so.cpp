#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DS{
    char name[10];
    char email[50];
}DS;
DS SV[10000];

int check(char a,char b){
    if (strcmp(a,b) < 0) return 1;
    return 0;
}
void quickSort(DS SV[],int l, int r){
    int i=l, j=r;
    char x[10];
    strcpy(x,SV[(l+r)/2].name);
    while (i<=j){
        while (check(SV[i].name,x)) i++;
        while (!check(SV[j].name,x)) j--;
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

int binarySearch(DS SV[], int l, int r, char x){
	if (r>=l){
		int mid = l+(r-l)/2;
		if (SV[mid].name == x)
			return mid;
		if (a[mid] > x)
			return binarySearch(a,l,mid-1,x);
		return binarySearch(a,mid+1,r,x);
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
        }
        if (strcmp(cmd,"Insert")) {scanf("%s %s",&SV[n].name,&SV[n].email); n++;}
        if (strcmp(cmd,"Insert")) {scanf("%s %s",&SV[n].name,&SV[n].email); n++;}

        if (strcmp(cmd,"Remove")) {
            char s[10];
            scanf("%s",s); n--;
        }
    }
    
}