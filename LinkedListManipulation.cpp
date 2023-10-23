#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int key;
    Node* next; 
};
Node* h = NULL;

Node*makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = v; p->next = NULL;
    return p;
}
Node* insertLastRecursive(Node* h, int v){
    if(h == NULL){
        return makeNode(v);
    }
    h->next = insertLastRecursive(h->next, v);
    return h;
}

Node* removeNodeRecursive(Node* h, int v){
    if(h == NULL) return NULL;
    if(h->key == v){
        Node* tmp = h; h = h->next; free(tmp); return h;
    }
    h->next = removeNodeRecursive(h->next, v);
    return h;
}
Node* reverse(Node *h){
    Node* p = h;
    Node* pp = NULL;
    Node* np = NULL;
    while(p != NULL){
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}
Node* addFirst(Node* h, int v){
    Node* p = makeNode(v);
    p->next = h;
    return p;
}
Node* find(Node* h, int k){
    for(Node* p = h; p != NULL; p = p->next){
        if(p->key == k) return p;
    }
    return NULL;
}
Node* addBefore(Node* h, int u, int v){
    //if(find(h,u) != NULL) return h;// do nothing
    if(h == NULL) return NULL;
    if(h->key == v){
        Node* q = makeNode(u);
        q->next = h; return q;
    }
    h->next = addBefore(h->next,u,v);
    return h;
}
Node* addAfter(Node* h, int u, int v){
    if(h == NULL) return NULL;
    if(h->key == v){
        Node* q = makeNode(u);
        q->next = h->next;
        h->next = q; return h;
    }
    h->next = addAfter(h->next,u,v);
    return h;
}
void print(Node* h){
    Node* p = h;
    while(p != NULL){
        printf("%d ",p->key);
        p = p->next;
    }
    printf("\n");
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d",&k);
        h = insertLastRecursive(h,k);
    }
    //print(h);
    while(true){
        char cmd[256];
        scanf("%s",cmd);

 

        if(strcmp(cmd,"#") == 0) break;

 

        if(strcmp(cmd,"addlast") == 0){
            int k;    scanf("%d",&k);
            if(find(h,k) == NULL)
                h = insertLastRecursive(h,k);
            //printf("after addlast, h = "); print(h);
        }else if(strcmp(cmd,"addfirst") == 0){
            int k;    scanf("%d",&k);
            if(find(h,k) == NULL)
            h = addFirst(h,k);
            //printf("after addfirst, h = "); print(h);
        }else if(strcmp(cmd,"addafter") == 0){
            int u, v; scanf("%d%d",&u,&v);
            if(find(h,u) == NULL)
                h = addAfter(h,u,v);
            //printf("after addafter, h = "); print(h);
        }else if(strcmp(cmd,"addbefore") == 0){
            int u, v; scanf("%d%d",&u,&v);
            if(find(h,u) == NULL)
                h = addBefore(h,u,v);
            //printf("after addbefore, h = "); print(h);
        }else if(strcmp(cmd,"remove") == 0){
            int k; scanf("%d",&k);
            h = removeNodeRecursive(h,k);
            //printf("after remove, h = "); print(h);
        }else if(strcmp(cmd,"reverse") == 0){
            h = reverse(h);
            //printf("after reverse, h = "); print(h);
        }
    }

 


}
void solve(char* fi, char* fo){
    freopen(fi,"r",stdin);
    solve();
    FILE* f = fopen(fo,"w");
    for(Node* p = h; p != NULL; p = p->next){
        fprintf(f,"%d ",p->key);
        printf("%d ",p->key);
    }
    fclose(f);
}
int main(){
    //char* fi = "test/input/5.txt";
    //char* fo = "test/output/5.txt";
    //solve(fi,fo);

 

    //freopen(fi,"r",stdin);

 

    solve();
    print(h);
}