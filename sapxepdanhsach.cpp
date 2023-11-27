#include<stdio.h>
#include<string.h>
typedef struct Data{
    char ho[10],dem[10],ten[10],birth[11];
} Data;
Data DS[100000];

int check(Data a,Data b){
    int k = strcmp(a.ten,b.ten);
    if (k < 0) return 1;
    if (k > 0) return 0;
    if (k == 0){
        k = strcmp(a.dem,b.dem);
        if (k < 0) return 1;
        if (k > 0) return 0;
        if (k == 0){
            k = strcmp(a.ho,b.ho);
            if (k < 0) return 1;
            if (k > 0) return 0;
            if (k == 0){
                k = strcmp(a.birth,b.birth);
                if (k < 0) return 1;
                if (k >= 0) return 0;
            }
        }
    }
    return 0;
}

void heapify(Data DS[], int i, int n){
    int l = 2*i;
    int r = 2*i+1;
    int max = i;
    if(l <= n && !check(DS[l],DS[i]))    max = l;
    if(r <= n && !check(DS[r],DS[max]))  max = r;
    if(max != i){ 
        Data tmp = DS[i];
        DS[i] = DS[max];
        DS[max] = tmp;
        heapify(DS,max,n);
    }
}
void buildHeap(Data DS[], int n) {
    for(int i = n/2; i >= 0; i--)   heapify(DS,i,n);
}
void heapSort(Data DS[], int n) {
    buildHeap(DS,n);
    for(int i = n-1; i > 0; i--){
        Data tmp = DS[i];
        DS[i] = DS[0];
        DS[0] = tmp;
        heapify(DS, 0, i-1); 
    }
}


int main(){
    int n;
    for(n=0;;n++){
        scanf("%s",DS[n].ho);
        if(strcmp(DS[n].ho,"#")==0) break;
        scanf("%s %s",DS[n].dem,DS[n].ten);
        scanf("%s",DS[n].birth);
    }

    heapSort(DS,n);

    for (int i=0;i<n;i++)
        printf("%s %s %s\n%s\n", DS[i].ho, DS[i].dem, DS[i].ten, DS[i].birth);
    printf("#");
    return 0;
}
