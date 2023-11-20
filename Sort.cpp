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

void selectionSort(int a[], int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if (a[min]>a[j]) min=j;
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int last=a[i];
        int j=i;
        while (j>0 && a[j-1]>last){a[j]=a[j-1]; j--;}
        a[j] = last;
    }
}

void bubbleSort(int a[], int n){
    int swapped;
    do{
        swapped=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                swapped=1;
            }
        }
    } while(swapped=1);
}

int main(){
    int a[10000];
    int n;   
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);

    // quickSort(a,0,n-1);
    // insertionSort(a,n);
    // selectionSort(a,n);
    bubbleSort(a,n);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
}
