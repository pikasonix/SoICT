#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    char text[21];
    int count;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root;

Node *makeNode(char *text){
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->text, text);
    p->count = 1;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *insert(Node *r, char *text){
    if (r == NULL) return makeNode(text);
    int c = strcmp(r->text, text);
    if (c < 0){
        r->rightChild = insert(r->rightChild, text);
        return r;
    }
    else if (c==0) {r->count++; return r;}
    else{
        r->leftChild = insert(r->leftChild, text);
        return r;
    }
}

Node *find(Node *r, char *text){
    if (r == NULL) return NULL;
    int c = strcmp(r->text, text);
    if (c == 0) return r;
    if (c < 0)  return find(r->rightChild, text);
    return find(r->leftChild, text);
}

void inOrder(Node *r){
    if (r == NULL) return;
    inOrder(r->leftChild);
    printf("%s %d\n", r->text, r->count);
    inOrder(r->rightChild);
}

void printList(){
    inOrder(root);
}

int main(){
    char s[21];
    while(!feof(stdin)){
        scanf("%s",s);
        root = insert(root,s);
    }
    find(root,s)->count--;
    printList();
}
