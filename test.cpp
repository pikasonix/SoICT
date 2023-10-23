#include <stdio.h>
#include <stdlib.h>

int X[1000000]={0};
int visited[1000000]={0};

int check(int k){
    if (k>0 && (X[k]%2)==(X[k-1]%2)) return 0;
    return 1;
}

void Inso(int n){
    for (int i=0;i<n;i++) printf("%d", X[i]);
    printf("\n");
}

void Try(int k, int n){
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            X[k] = i;
            visited[i]=1;
            if (check(k))
                if (k == n-1) Inso(n);
                else Try(k+1,n);
            visited[i]=0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    if (n < 2) printf("Input error");
    Try(0,n);
}