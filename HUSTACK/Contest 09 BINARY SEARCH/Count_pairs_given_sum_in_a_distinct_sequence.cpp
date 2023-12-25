#include <stdio.h>
int a[1000000];
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
    int n,x,count=0;
    scanf("%d %d",&n,&x);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        if(a[i]>x) break;
        if(binarySearch(a,i+1,n-1,x-a[i])!= -1) count++;
    }
	printf("%d",count);
	return 0;
}
