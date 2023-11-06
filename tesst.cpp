#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;
Node* root;

#define MAX_HEAP_SIZE 1024

Node* find(Node* r, int u) {
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    Node* p = find(r->leftChild, u);
    if (p!=NULL) return p;
    return find(r->rightChild, u);
}

Node* makeNode(int u) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

void AddLeftChild(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    if (r->leftChild==NULL) r->leftChild = makeNode(u);
}

void AddRightChild(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    if (r->rightChild==NULL) r->rightChild = makeNode(u);
}
int check=1;
void IsMaxHeap(Node* p) {
    if (p == NULL) return;
    if (p->leftChild != NULL)
        if (p->id < p->leftChild->id)  check=0;
    if (p->rightChild != NULL)
        if (p->id < p->rightChild->id) check=0;
    IsMaxHeap(p->leftChild);
    IsMaxHeap(p->rightChild);
}

int main() {
    int u, v;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);                    
            root = makeNode(u);
        } 
        else if (strcmp(cmd, "AddLeftChild") == 0) {
            scanf("%d %d", &v, &u);             
            AddLeftChild(u, v);
        } 
        else if (strcmp(cmd, "AddRightChild") == 0) {
            scanf("%d %d", &v, &u);     
            AddRightChild(u, v);
        }  
        else if (strcmp(cmd, "IsMaxHeap") == 0) {
            scanf("%d", &u); 
            IsMaxHeap(find(root,u));
            printf("%d\n",check);
            check=1;
        }
    }
}
