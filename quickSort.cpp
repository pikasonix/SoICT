#include<stdio.h>
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
int main(){
    int n;
    int a[1000000];
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
}
