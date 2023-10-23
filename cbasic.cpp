#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* top = NULL; 
Node* head = NULL;
Node* tail = NULL;

void pushQueue(Node** top, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = *top;
    if (*top != NULL)
        (*top)->prev = newNode;
    *top = newNode;
}

char popQueue(Node** top) {
    Node* temp = *top;
    char value = temp->value;
    *top = temp->next;
    if (*top != NULL)
        (*top)->prev = NULL;
    return value;
}

void enqueue(Node** head, Node** tail, char value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head == NULL){
        *head = newNode;
        *tail = newNode;
    } else {
		Node *temp;
		temp = *tail;
        newNode->prev = *tail;
        temp->next = newNode;
        *tail = newNode;
    }
}

char dequeue(Node** head, Node** tail){
    if (*head == NULL) return NULL;
    Node* temp = *head;
    char value = temp->value;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    else
        *tail = NULL;
    return value;
}

void DectoHex(double k){
    int nguyen=k;
    double thapphan=k-nguyen;

    while (nguyen>0) {
        int num=nguyen%16;
        if (num<10) 	pushQueue(&top,num+'0');
        	else 		pushQueue(&top,num-10+'A');
        nguyen/=16;
    }

    while (thapphan>0) {
        thapphan*=16;
        int digit=thapphan;
        if (digit<10)
            enqueue(&head,&tail,digit+'0');
        else
            enqueue(&head,&tail,digit-10+'A');
        thapphan-=digit;
    }
    while (top!=NULL) printf("%c",popQueue(&top));
    if (head!=NULL) printf(".");
    while (head!=NULL) printf("%c",dequeue(&head,&tail));
}

int main(){
    double k;
    scanf("%lf",&k);
	if (k<1) {printf("0");}
    DectoHex(k);
    return 0;
}