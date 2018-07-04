#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 11
#define Null -1

typedef struct Treenode{
    int node;
    struct Treenode *left;
    struct Treenode *right;
} BST;
// 
// ===================================
typedef struct _q{
    int Data[MAXSIZE];
    int front;
    int rear;
} Queue;
// 
// ===================================
BST* MakeTree(int nodenum);
Queue* MakeQueue();
void AddQueue(Queue* *pQ, int item);
int DeQueue(Queue* *pQ);
// 
// ===================================
int main(int argc, char const *argv[]){
    int N, L;
    BST *T;

    scanf("%d", &N);
    
    if (N){
        
        scanf("%d", &L);
        T = MakeTree(N);
        // while(L--){
        //     isSame(T1, T2);
        // }

    }
    
    return 0;
}

// 
// ===================================
BST* MakeTree(int nodenum){
    
    BST *Head, *Rear;
    Head = (BST*)malloc(sizeof(BST));
    Head->node = Null;
    Head->left = NULL;
    Head->right = NULL;
    Rear = Head;

    while(nodenum--){
        BST *p;
        int data;
        p = (BST*)malloc(sizeof(BST));
        
        scanf("%d",&data);
        p->node = data;
        p->left = NULL;
        p->right = NULL;

        while ( (Rear->left!=NULL) || (Rear->right!=NULL) ){
            if(data > Rear->node){
                Rear = Rear->right;
            }else{
                Rear = Rear->left;
            }
        }
    }

    return Head;
}

// 
// ===================================
Queue* MakeQueue(){
    Queue *p;
    int i;
    p = (Queue*)malloc(sizeof(Queue));
    p->front = 0;
    p->rear = 0;
    for(i=0; i<MAXSIZE; i++){
        p->Data[i] = Null;
    }

    return p;
}
// 
// ===================================
void AddQueue(Queue* *pQ, int item){
    (*pQ)->Data[(*pQ)->rear++] = item;
    // (*pQ)->rear++;
}
// 
// ===================================
int DeQueue(Queue* *pQ){
    int item;
    item = (*pQ)->Data[(*pQ)->front++];
    // (*pQ)->front ++;
    return item;
}

// 
// ===================================
void MidTraversal(BST* *pT){
    BST *i;
    Queue *Q;
    Q = MakeQueue();

}