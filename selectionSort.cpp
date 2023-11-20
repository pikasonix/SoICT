#include<stdio.h>
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
int main(){
    int n;
    int a[100000];
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    selectionSort(a,n);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
}
