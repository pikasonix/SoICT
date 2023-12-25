#include<stdio.h>

int main(){
   int N,T,S,R;
   int a,t,s,r;
   int visited[100000];
   scanf("%d %d %d %d",&N,&T,&S,&R);
   for(int i=1;i<=N;i++){
        scanf("%d %d %d %d",&a,&t,&s,&r);
        visited[s]++;
   }
   int min=T;
   for(int i=1;i<=S;i++)
        if (min>visited[i]) min=visited[i];
   printf("%d",T-min);
}