/* chuan ko sua*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* top = NULL; 
Node* head = NULL;
Node* tail = NULL;

void push(Node** top, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = *top;
    if (*top != NULL)
        (*top)->prev = newNode;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return '\0';
    }
    Node* temp = *top;
    char value = temp->value;
    *top = temp->next;
    if (*top != NULL)
        (*top)->prev = NULL;
    free(temp);
    return value;
}

void enqueue(Node** head, Node** tail, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

char dequeue(Node** head, Node** tail) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return '\0';
    }
    Node* temp = *head;
    char value = temp->value;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    else
        *tail = NULL;
    free(temp);
    return value;
}


void decimalToHexadecimal(double number) {
    int integerPart = (int)number;
    double fractionalPart = number - integerPart;

   
    while (integerPart > 0) {
        int remainder = integerPart % 16;
        if (remainder < 10)
            push(&top, remainder + '0');
        else
            push(&top, remainder - 10 + 'A');
        integerPart /= 16;
    }

 
    while (fractionalPart > 0) {
        fractionalPart *= 16;
        int digit = (int)fractionalPart;
        if (digit < 10)
            enqueue(&head, &tail, digit + '0');
        else
            enqueue(&head, &tail, digit - 10 + 'A');
        fractionalPart -= digit;
    }

   
    printf("Output: ");
    while (top != NULL) {
        printf("%c", pop(&top));
    }
    printf(".");
    while (head != NULL) {
        printf("%c", dequeue(&head, &tail));
    }
    printf("\n");
}

int main() {
    double number;
    printf("Input: ");
    scanf("%lf", &number);
    decimalToHexadecimal(number);
    return 0;
}