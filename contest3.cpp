#include<stdio.h>

int main(){
    int n,a,count;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if (a%2!=0) count++;
    }
    printf("%d %d",count,n-count);
}