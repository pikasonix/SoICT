#include <stdio.h>
#include<time.h>
int a[1000000];
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

void quickSort(int a[], int L, int R) {
    if (L < R) {
        int index = (L + R) / 2;
        index = partition(a, L, R, index);
        if (L < index) quickSort(a, L, index - 1);
        if (index < R) quickSort(a, index + 1, R);
    }
}

int main() {
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
