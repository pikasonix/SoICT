#include<stdio.h>
#include<string.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char s[256];
    for (int i=0;i<n;i++){
        scanf("%s",s);
        int sum=0;
        int k=strlen(s);
        for(int j=0;j<k;j++)
            sum = (sum*256+s[j])%m;
        printf("%d\n",sum);
    }
}
