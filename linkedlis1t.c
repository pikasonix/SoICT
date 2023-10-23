#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* makenode(int val) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}

void addelement(Node** head, int x) {
    Node* newnode = makenode(x);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    Node* tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}

void removeFirst(Node** head, int v) {
    if (*head == NULL) return;
    Node* tmp = *head;
    if (tmp->val == v) {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp->next != NULL) {
        if (tmp->next->val == v) {
            Node* tmp1 = tmp->next;
            tmp->next = tmp->next->next;
            free(tmp1);
            return;
        }
        tmp = tmp->next;
    }
}

void removeAllNode(Node** head, int v) {
    if (*head == NULL) return;
    while (*head != NULL && (*head)->val == v) {
        Node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    Node* tmp = *head;
    while (tmp != NULL) {
        while (tmp->next != NULL && tmp->next->val == v) {
            Node* tmp1 = tmp->next;
            tmp->next = tmp->next->next;
            free(tmp1);
        }
        tmp = tmp->next;
    }
}

int count(Node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void reverse(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void print(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}



int main() {
    Node* head = NULL;
    int choice;
    while (1) {
        printf("-----------------------\n");
        printf("1. Nhap vao mang:\n");
        printf("2. Xoa node dau tien co gia tri v\n");
        printf("3. Xoa tat ca cac node co gia tri v\n");
        printf("4. Dem so node: \n");
        printf("5. Reverse mang: \n");
        printf("6. In ra mang: \n");
        printf("-----------------------\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int n;
            printf("Nhap vao so luong node: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                int val;
                scanf("%d", &val);
                addelement(&head, val);
            }
        } else if (choice == 2) {
            printf("Nhap node dau tien can xoa: ");
            int v;
            scanf("%d", &v);
            removeFirst(&head, v);
        } else if (choice == 3) {
            printf("Nhap node ma minh muon xoa tat ca trong dslk: ");
            int v;
            scanf("%d", &v);
            removeAllNode(&head, v);
        } else if (choice == 4) {
            printf("So node la: ");
            printf("%d\n", count(head));
        } else if (choice == 5) {
            reverse(&head);
        } else if (choice == 6) {
            print(head);
        } else {
            break;
        }
    }
    while (head != NULL) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}

