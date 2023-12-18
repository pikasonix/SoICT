#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hash(char* s,int m){
    int rs=0; int k=strlen(s);
    for(int i=0;i<k;i++) rs=(rs*255+s[i])%m;
    return rs;
}

typedef struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

Node *makeNode(int data){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *r, int data){
    if (r == NULL) return makeNode(data);
    if (r->data < data){
        r->rightChild = insert(r->rightChild, data);
        return r;
    }
    else if (r->data == data) return r;
    else{
        r->leftChild = insert(r->leftChild, data);
        return r;
    }
}

Node *find(Node *r, int data){
    if (r == NULL) return NULL;
    if (r->data == data) return r;
    if (r->data < data)  return find(r->rightChild, data);
    return find(r->leftChild, data);
}

int main(){
    char s[51];
    int mod = 1000000007;
    int i;
    for(i=0;;i++){
        scanf("%s",s);
        if(strcmp(s,"*")==0) break;    
        root = insert(root,hash(s,mod));
    }
    for(i=0;;i++){
        scanf("%s",s);
        char s1[51];
        if(strcmp(s,"***")==0) break;
        if (strcmp(s,"find")==0){
            scanf("%s",s1);
            if(find(root,hash(s1,mod))==NULL) printf("0\n");
                else printf("1\n");
        }
        else if (strcmp(s,"insert")==0){
            scanf("%s",s1);
            if(find(root,hash(s1,mod))==NULL) {printf("1\n"); root = insert(root,hash(s1,mod));}
                else printf("0\n");
        }
    }
}
