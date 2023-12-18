#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int maxValue(Node* r){
    if (r == NULL) return 0;
    int leftMax = maxValue(r->left);
    int rightMax = maxValue(r->right);
    int value = 0;
    if (leftMax > rightMax) value = leftMax;
        else value = rightMax;
    if (value < r->id) value = r->id;
    return value;
}
 
int minValue(Node* r){
    if (r == NULL) return 100000000;
    int leftMax = minValue(r->left);
    int rightMax = minValue(r->right);
    int value = 0;
    if (leftMax < rightMax) value = leftMax;
    else value = rightMax;
    if (value > r->id) value = r->id;
    return value;
}
 
int checkBST(Node* r){
    if (r == NULL)                                        return 1;
    if (r->left != NULL && maxValue(r->left) > r->id)     return 0;
    if (r->right != NULL && minValue(r->right) < r->id)   return 0;
    if (!checkBST(r->left) || !checkBST(r->right))        return 0;
    return 1;
}
 
int sumKeys(Node* r){
    if (r == NULL) return 0;
    return r->id+sumKeys(r->left)+sumKeys(r->right);
}

int main() {
    int u, v;
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
    printf("%d %d",checkBST(root),sumKeys(root));
}