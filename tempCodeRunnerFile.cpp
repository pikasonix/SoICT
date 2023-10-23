#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,a[1000];
typedef struct Node{
    int value;
    struct Node* next;
}Node;
Node*makeNode(int v){
    Node*p=(Node*)malloc(sizeof(Node));
    p->value=v; p->next =NULL;
    return p;
}
Node* first,*last;

void addlast(){
    int k;
    scanf("%d",&k);
    Node*p=makeNode(k);
    if (last==NULL && first == NULL){
        first = p; last = p; return;
    } 
    Node *q;
    for(q = first; q != NULL; q = q->next)
        if (q->value == k) return;
    for(q = first; q->next != NULL; q = q->next);
    q->next=p;
}

void addfirst(){
    int k;
    scanf("%d",&k);
    Node*p=makeNode(k);
    if (last==NULL && first == NULL){
        first = p; last = p; return;
    } 
    for(Node* p = first; p != NULL; p = p->next)
        if (p->value == k) return;
    p->next=first; first=p;
}

void addafter(){
    int u,v;
    scanf("%d %d",&u,&v);
    Node*p=makeNode(v);
    if (last==NULL && first == NULL) return;
        for(Node* p = first; p != NULL; p = p->next)
            if (p->value == v){
                Node*q=makeNode(u);
                for(Node* q = first; q != NULL; q = q->next)
                    if (q->value == u) return;
                q->next=p->next; p->next = q;
            }
}

void addbefore(){
    int u,v;
    scanf("%d %d",&u,&v);
    Node *p=makeNode(v);
    if (last==NULL && first == NULL){
        first = p; last = p;
    } else{
    Node* prev = NULL;
    Node *p = first;
    while (p != NULL && p->value != v) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) return;
    Node* q = makeNode(u);
    if (p == first){
        q->next = p;
        first = q;
        return;
    }
    prev->next = q;
    q->next = p;
    }
}

void remove(){
    int k;
    scanf("%d",&k);
    Node *p=first;
    if (last==NULL && first == NULL) return;
    if (first->value==k) {first = first->next; return;}
    // printf("AA");
    while(p->next->value != k && p != NULL) p=p->next;
    if (p->next==NULL) return;
    printf("AA");
    p->next = p->next->next;
}

void reverse(){
    Node *p= first;
    Node *next=NULL,*prev=NULL;
    while(p != NULL){
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    first = prev;  
}

int main(){
    first = NULL; last = NULL;
    scanf("%d",&n);
    for (int i=0;i<n;i++) addlast();
    while(1){
        char s[10];
        scanf("%s",s);
        if (strcmp(s,"#")==0) break;
        if (strcmp(s,"addlast")==0) addlast();
        if (strcmp(s,"addfirst")==0) addfirst();
        if (strcmp(s,"addafter")==0) addafter();
        if (strcmp(s,"addbefore")==0) addbefore();
        if (strcmp(s,"remove")==0) remove();
        if (strcmp(s,"reverse")==0) reverse();
        for(Node* p = first; p != NULL; p = p->next) printf("%d ",p->value); printf("\n");
    }
    for(Node* p = first; p != NULL; p = p->next)
        printf("%d ",p->value);
}
