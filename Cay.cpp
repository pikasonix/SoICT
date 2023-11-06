#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* parent;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;
Node* root;

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

Node* makeNode(int u,int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->parent = find(root,v);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* addLast(Node* p, int u, int v) {
    if (p == NULL) return makeNode(u,v);
    p->rightSibling = addLast(p->rightSibling,u,v);
    return p;
}

void Insert(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild,u,v);
}

void PreOrder(Node* p) {
    if (p == NULL) return;
    printf("%d ", p->id);
    PreOrder(p->leftMostChild);
    PreOrder(p->rightSibling);
}

void InOrder(Node* r) {
    if (r->leftMostChild==NULL){
        printf("%d ",r->id);
    } else {
        InOrder(r->leftMostChild);
        printf("%d ",r->id);
        Node*p=r->leftMostChild->rightSibling;
        while (p!=NULL){
            InOrder(p);
            p=p->rightSibling;
        }
    }
}

void PostOrder(Node* p) {
    if (p == NULL) return;
    PostOrder(p->leftMostChild);
    printf("%d ", p->id);
    PostOrder(p->rightSibling);
}

int Height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    Node* q = p->leftMostChild;
    while(q != NULL){
        int h = Height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}

int Depth(Node *p){
    Node*q=p;
    int d=0;
    while (q!=NULL){
        d++;
        q=q->parent;
    }
    return d;
}

int CountLeaves(Node* p) {
    if (p == NULL) return 0;
    if (p->leftMostChild == NULL) return 1;
    int cnt = 0;
    Node* q = p->leftMostChild;
    while (q != NULL) {
        cnt += CountLeaves(q);
        q = q->rightSibling;
    }
    return cnt;
}
int CountChild(Node*p,int k){
    if (p->leftMostChild == NULL) return 0;
    Node* q = p->leftMostChild;
    int count=0;
    while (q != NULL) {
        q = q->rightSibling;
        count++;
    }
    // printf("%d %d | ",p->id,count);
    return (count==k);
}
int output=0;
void CountKChildren(Node* p, int k) {
    if (p == NULL) return;
    if (p->leftMostChild == NULL) return;
    Node* q = p->leftMostChild;
    while (q != NULL) {
        CountKChildren(q, k);
        output+=CountChild(q,k);
        q = q->rightSibling;
    }
}


int main() {
    int u, v;

    // root = makeNode(10);
    // root->leftMostChild=makeNode(11);
    // root->leftMostChild->rightSibling=makeNode(1);
    // root->leftMostChild->rightSibling->rightSibling=makeNode(3);
    // InOrder1(root);
    
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);                    
            root = makeNode(u,NULL);
        } 
        else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);             
            Insert(u, v);
        } 
        else if (strcmp(cmd, "InOrder") == 0) {
            InOrder(root);
            printf("\n");
        }  
        else if (strcmp(cmd, "PreOrder") == 0) {
            PreOrder(root);
            printf("\n");
        } 
        else if (strcmp(cmd, "PostOrder") == 0) {
            PostOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "Height") == 0) {
            scanf("%d", &u);
            Node*p = find(root,u);                    
            printf("%d\n",Height(p));
        } 
        else if (strcmp(cmd, "Depth") == 0) {
            scanf("%d", &u);
            Node*p = find(root,u);   
            printf("%d\n",Depth(p));                 
        } 
        else if (strcmp(cmd, "CountLeaves") == 0) {
            scanf("%d", &u);
            Node*p = find(root,u);   
            printf("%d\n",CountLeaves(p));                 
        } 
        else if (strcmp(cmd, "CountKChildren") == 0) {
            int k;
            scanf("%d %d", &u,&k);
            Node*p = find(root,u);   
            output=0;
            CountKChildren(p,k);
            printf("%d\n",output+CountChild(p,k));                 
        } 
    }
}
