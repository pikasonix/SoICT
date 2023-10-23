/* XẾP HẬU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n,m,q,x[MAX][MAX];

int main(){
    scanf("%d",&t);
    for (int k=1;k<=t;k++){
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                scanf("%d",&q);
                if (q==1){
                    if (x[i][j]=1){printf("0"); break;}
                    for (int p=1;p<=n;p++){x[i][p]=1; x[p][j]=1;}
                }
            }
                
    }
    TRY(1);
}
