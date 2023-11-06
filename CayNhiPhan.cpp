#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;
Node* root;

Node* find(Node* r, int u) {
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    Node* p = find(r->left, u);
    if (p!=NULL) return p;
    return find(r->right, u);
}

Node* makeNode(int u) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void AddLeft(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    if (r->left==NULL) r->left = makeNode(u);
}

void AddRight(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    if (r->right==NULL) r->right = makeNode(u);
}

int Height(Node* p){
    if(p == NULL) return 0;
    int maxH = 0;
    int hl = Height(p->left);
    if(maxH < hl) maxH = hl;
    int hr = Height(p->right);
    if(maxH < hr) maxH = hr;
    return maxH + 1;
}

int Check(Node *p, int *h) {
    int leftHeight = 0, rightHeight = 0;
    int l=0, r=0;

    if (p == NULL){*h = 0; return 1;}

    l = Check(p->left,&leftHeight);
    r = Check(p->right,&rightHeight);

    *h = fmax(leftHeight,rightHeight) + 1;

    if (abs(leftHeight - rightHeight) > 1) return 0;
    else return (l && r);
}

int main() {
    clock_t t = clock();
    int u, v;
    int h=0;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);                    
            root = makeNode(u);
        } 
        else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);             
            AddLeft(u, v);
        } 
        else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);     
            AddRight(u, v);
        } 
    }
    printf("%d %d",Check(root,&h),Height(root));
    printf("%ld",t);
}
