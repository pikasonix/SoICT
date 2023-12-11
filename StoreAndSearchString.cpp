#include<stdio.h>
#include<string.h>
int hash(char* s,int m){
    int rs=0; int k=strlen(s);
    for(int i=0;i<k;i++) rs=(rs*255+s[i])%m;
    return rs;
}

void quickSort(int a[],int l, int r){
    int i=l, j=r;
    int x=a[(l+r)/2];
    while (i<=j){
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++; j--;
        }
    }
    if (l<j) quickSort(a,l,j);
    if (i<r) quickSort(a,i,r);
}

int binarySearch(int a[], int l, int r, int x){
	if (r>=l){
		int mid = l+(r-l)/2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearch(a,l,mid-1,x);
		return binarySearch(a,mid+1,r,x);
	}
	return -1;
}

int main(){
    char s[51];
    int mod = 100000;
    int a[100000];
    int i;
    for(i=0;;i++){
        scanf("%s",s);
        if(strcmp(s,"*")==0) break;
        a[i]=hash(s,mod);
    }
    int n=i;
    quickSort(a,0,n-1);
    for(i=0;;i++){
        scanf("%s",s);
        if(strcmp(s,"***")==0) break;
        if (strcmp(s,"find")==0){
            scanf("%s",s);
            if(binarySearch(a,0,n-1,hash(s,mod))==-1) printf("1\n");
                else printf("0\n");
        }
        else if (strcmp(s,"insert")==0){
            scanf("%s",s);
            if(binarySearch(a,0,n-1,hash(s,mod))==-1) printf("0\n");
                else {printf("1\n"); a[n]=hash(s,mod); n++; quickSort(a,0,n-1);}
        }
    }
}