#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define Null -1
#define Init -99

struct TreeNode{
    // char node;
    int node;
    int left;
    int right;
} Tree[MAXSIZE];

typedef struct _q{
    int Data[MAXSIZE];
    int front;
    int rear;
} Queue;

int MakeTree(struct TreeNode Tree[], int *node_num);
Queue* MakeQueue();
void AddQueue(Queue* *pQ, int item);
int DeQueue(Queue* *pQ);
void MidTraversal(int Root, int node_num);

int main(int argc, char const *argv[]){
    
    int Root;
    int node_num;
    Root = MakeTree(Tree,&node_num);
    MidTraversal(Root, node_num);
    
    // int i;
    // for (i = 0; i < 8; ++i){
    //     printf("node:%d\n", Tree[i].node);
    //     printf("left:%d\n", Tree[i].left);
    //     printf("right:%d\n", Tree[i].right);
    // }
    // printf("Root:%d\n", Root);

    return 0;

}

int MakeTree(struct TreeNode Tree[], int *node_num){

    int num, i, Root;
    scanf("%d\n", &num);
    int check[num];
    *node_num = num;
    
    if (num){

        for (i = 0; i < num; ++i){
            check[i] = 0;
        }

        for (i = 0; i < num; ++i){
            // char data;
            char l, r;
            scanf("%c %c\n", &l, &r);
            // scanf("%c %c %c\n",&data, &l, &r);
            Tree[i].node = i;
            if(l != '-'){
                Tree[i].left = l - '0';
                check[Tree[i].left] = 1;
            }else{
                Tree[i].left = Null;
            }

            if(r != '-'){
                Tree[i].right = r - '0';
                check[Tree[i].right] = 1;
            }else{
                Tree[i].right = Null;
            }
        }

        for (i = 0; i < num; ++i){
            if(check[i] != 1){
                break;
            }
        }
        Root = i;

    }else{
        Root = -1;
    }

    return Root;

}

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

void AddQueue(Queue* *pQ, int item){
    (*pQ)->Data[(*pQ)->rear++] = item;
    // (*pQ)->rear++;
}

int DeQueue(Queue* *pQ){
    int item;
    item = (*pQ)->Data[(*pQ)->front++];
    // (*pQ)->front ++;
    return item;
}

void MidTraversal(int Root, int node_num){
    Queue *Q;
    int data;
    Q = MakeQueue();
    int i;
    int flag = 0;

    AddQueue(&Q, Root);
    // for(i=0; i<MAXSIZE; i++){
    //     printf("Q:%d\n", Q->Data[i]);
    // }
    // printf("front:%d\n", Q->front);
    // printf("rear:%d\n", Q->rear);
    while(Q->front != Q->rear){
        data = DeQueue(&Q);
        if(Tree[data].left == Null && Tree[data].right == Null){
            if(flag == 0){
                printf("%d", data);
                flag = 1;
            }else{
                printf(" %d", data);
            }
            
        }
        if(Tree[data].left != Null){
            AddQueue(&Q, Tree[data].left);
        }
        if(Tree[data].right != Null){
            AddQueue(&Q, Tree[data].right);
        }
    }
}