#include<stdio.h>
#include<time.h>
int a[100000000], a1[100000000];
// quickSort
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
// quickSort (slide)
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int L, int R, int indexPivot) {
    int pivot = a[indexPivot];
    swap(&a[indexPivot], &a[R]);
    int storeIndex = L;
    for (int i = L; i <= R - 1; i++) {
        if (a[i] < pivot) {
            swap(&a[storeIndex], &a[i]);
            storeIndex++;
        }
    }
    swap(&a[storeIndex], &a[R]);
    return storeIndex;
}
void quickSort2(int a[], int L, int R) {
    if (L < R) {
        int index = (L + R) / 2;
        index = partition(a, L, R, index);
        if (L < index) quickSort2(a, L, index - 1);
        if (index < R) quickSort2(a, index + 1, R);
    }
}
// selectionSort
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
// insertionSort
void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int last=a[i];
        int j=i;
        while (j>0 && a[j-1]>last){a[j]=a[j-1]; j--;}
        a[j] = last;
    }
}
// bubbleSort
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
    } while(swapped==1);
}
// mergeSort
void merge(int l, int x, int r){
    int i=l;    int j=x+1;
    for(int k=l;k<=r;k++){
        if(i>x){ a1[k] = a[j]; j++;}
        else if(j > r){a1[k] = a[i]; i++;}
        else{
            if(a[i]<a[j]){a1[k] = a[i]; i++;}
            else {a1[k] = a[j]; j++;}
        }
    }
    for(int k = l; k <= r; k++) a[k] = a1[k];
}
void mergeSort(int l, int r) {
    if(l < r){
        int x = (l+r)/2;
        mergeSort(l,x);
        mergeSort(x+1,r);
        merge(l,x,r);
    }
}
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

// int main(){
//     int n;   
//     scanf("%d",&n);
//     for (int i=0;i<n;i++) scanf("%d",&a[i]);

//     // quickSort(a,0,n-1);
//     // quickSort2(a,0,n-1);
//     // insertionSort(a,n);
//     // selectionSort(a,n);
//     // bubbleSort(a,n);
//     // mergeSort(0,n-1);
//     // heapSort(a,n);
//     for (int i=0;i<n;i++) printf("%d ",a[i]);
// }

int main() {
  FILE *f = fopen("input.txt","r");
    int n;
    fscanf(f,"%d",&n);
    for (int i=0;i<n;i++) fscanf(f,"%d",&a[i]);
    clock_t begin = clock();
    /* Test mảng ngẫu nhiên 10^6 phần tử */
    // heapSort(a,n);       /*Time run: 0.297*/
    // mergeSort(0,n-1);    /*Time run: 0.172*/
    // quickSort2(a,0,n-1); /*Time run: 0.172*/
    // quickSort(a,0,n-1);  /*Time run: 0.119*/
 
    /* Test mảng ngẫu nhiên 10^4 phần tử */
    // bubbleSort(a,n);     /*Time run: 0.315*/
    // selectionSort(a,n);  /*Time run: 0.095*/
    // insertionSort(a,n);  /*Time run: 0.064*/
    
    clock_t end = clock();
    printf("\nTime run: %f",(float)(end-begin)/CLOCKS_PER_SEC);
    fclose(f);
}