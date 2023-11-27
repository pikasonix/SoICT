#include<stdio.h>
#include<time.h>
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
int main(){
    FILE *f = fopen("input.txt","r");
    int n;
    fscanf(f,"%d",&n);
    for (int i=0;i<n;i++) fscanf(f,"%d",&a[i]);
    clock_t begin = clock();
    quickSort(a,0,n-1);

    clock_t end = clock();
    printf("\nTime run: %f",(float)(end-begin)/CLOCKS_PER_SEC);
    fclose(f);
}
