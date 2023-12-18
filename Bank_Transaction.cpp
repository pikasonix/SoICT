#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
    char from_account[21];
    char to_account[21];
    int money;
    char time_point[9];
    char atm[11];
}Data;

void quickSort(Data a[],int l, int r){
    int i=l, j=r;
    Data x=a[(l+r)/2];
    while (i<=j){
        while (a[i]<x.from_account) i++;
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
    /* Input data */
    Data a[100000];
    int n;
    for (n=0;;n++){
        char cmd[21];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        strcpy(a[n].from_account,cmd);
        scanf("%s %d %s %s",a[n].to_account, a[n].money, a[n].time_point, a[n].atm);
    }  
    --n;
    /* Input command */
    while(1){
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        else if (strcmp(cmd, "?number_transactions") == 0) {
            printf("%d\n",n+1);
        } 
        else if (strcmp(cmd, "?total_money_transaction") == 0) { 
            int sum=0;      
            for (int i=0;i<n;i++) sum+=a[i].money;
            printf("%d\n",sum);
        } 
        else if (strcmp(cmd, "?list_sorted_accounts") == 0) {
            quickSort(a,0,n-1);          
            AddRight(u, v);
        }  
    }  
    printf("%d %d",checkBST(root),sumKeys(root));
}