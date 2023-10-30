#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;

Node* root;

Node* makeNode(int u) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* find(Node* r, int u) {
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        Node* q = find(p, u);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

Node* addLast(Node* p, int u) {
    if (p == NULL) return makeNode(u);
    p->rightSibling = addLast(p->rightSibling, u);
    return p;
}

void Insert(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild, u);
}

void PreOrder(Node* p) {
    if (p == NULL) return;
    printf("%d ", p->id);
    PreOrder(p->leftMostChild);
    PreOrder(p->rightSibling);
}

void InOrder(Node* p) {
    if (p == NULL) return;
    InOrder(p->leftMostChild);
    printf("%d ", p->id);
    InOrder(p->rightSibling);
}

void PostOrder(Node* p) {
    if (p == NULL) return;
    PostOrder(p->leftMostChild);
    PostOrder(p->rightSibling);
    printf("%d ", p->id);
}


int main() {
    int u, v;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);                    root = makeNode(u);
        } 
        else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);             Insert(u, v);
        } 
        else if (strcmp(cmd, "InOrder") == 0)   InOrder(root);
        else if (strcmp(cmd, "PreOrder") == 0)  PreOrder(root);
        else if (strcmp(cmd, "PostOrder") == 0) PostOrder(root);
    }
}