#include<stdio.h>
#include<time.h>
int a[1000000], a1[1000000];

// heapSort
void heapify(int a[], int i, int n){
    int l = 2*i;
    int r = 2*i+1;
    int max = i;
    if(l <= n && a[l] > a[i])    max = l;
    if(r <= n && a[r] > a[max])  max = r;
    if(max != i){ 
        int tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
        heapify(a,max,n);
    }
}
void buildHeap(int a[], int n) {
    for(int i = n/2; i >= 0; i--)   heapify(a,i,n);
}
void heapSort(int a[], int n) {
    buildHeap(a,n);
    for(int i = n-1; i > 0; i--){
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heapify(a, 0, i-1); 
    }
}

int main(){
    int n;   
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    heapSort(a,n);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
}
