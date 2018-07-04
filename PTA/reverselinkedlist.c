// chenqumi@20171226
// PTA reversing linked list
#include <stdio.h>
#include <stdlib.h>

/*
1. read data and store to a linked list
2. right order linked list
3. using 2 stacks to finish reversing
*/

/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/

typedef struct _node{
    int preadd;
    int data;
    int nextadd;
    struct _node *link;
} linkedlist;

//
// ==============================================
typedef struct _stack{
    linkedlist *pointer;
    struct _stack *link;
} Stack;

//
// ==============================================
linkedlist* ReadData();
Stack* MakeStack();
void Push(Stack* *pStack, linkedlist *item);
linkedlist* Pop(Stack* *pStack);
int CountStack(Stack* *pStack);
int IsEmpty(Stack* *pStack);
void reverse(linkedlist* *pHead, int Knum);

//
// ==============================================
int main(int argc, char const *argv[]){
    int Knum;
    linkedlist *Head;
    Head = ReadData(&Knum);
    reverse(&Head, Knum);
    return 0;
}

//
// ==============================================
linkedlist* ReadData(int *Knum){

    int init, num, k, loop;
    linkedlist *tmp, *rear;
    tmp = (linkedlist*)malloc(sizeof(linkedlist));
    tmp->link = NULL;
    rear = tmp;

    scanf("%d %d %d",&init,&num,&k);
    *Knum = k;
    loop = num;
    while(num--){
        int pre, d, next;
        linkedlist *p;
        scanf("%d %d %d",&pre,&d,&next);
        p = (linkedlist*)malloc(sizeof(linkedlist));
        p->preadd = pre;
        p->data = d;
        p->nextadd = next;
        p->link = NULL;
        rear->link = p;
        rear = p;
    }

    /* right ordered linked list */
    linkedlist *head;
    linkedlist *rear_head;
    linkedlist *t;
    //rear = tmp;
    head = (linkedlist*)malloc(sizeof(linkedlist));
    head->link = NULL;
    rear_head = head;

    while(loop--){
        rear = tmp;
        while(rear->link && rear->link->preadd != init){
            rear = rear->link;
        }
        t = rear->link;
        rear->link = t->link;
        rear_head->link = t;
        t->link = NULL;
        rear_head = t;

        init = rear_head->nextadd;
    }
    t = head;
    head = head->link;
    free(t);

    return head;
}

//
// ==============================================
Stack* MakeStack(){
    Stack *p;
    p = (Stack*)malloc(sizeof(Stack));
    p->link = NULL;

    return p;
}

//
// ==============================================
void Push(Stack* *pStack, linkedlist *item){
    Stack *p, *tmp;
    p = (Stack*)malloc(sizeof(Stack));
    p->pointer = item;
    
    tmp = (*pStack)->link;
    (*pStack)->link = p;
    p->link = tmp;
}

//
// ==============================================
linkedlist* Pop(Stack* *pStack){
    linkedlist* item;
    Stack *p;
    p = (*pStack)->link;
    (*pStack)->link = p->link;
    item = p->pointer;
    return item;
}

//
// ==============================================
int CountStack(Stack* *pStack){
    Stack *i;
    int count = 0;
    for (i = (*pStack); i; i = i->link){
        if (i->pointer != NULL){
            count ++;
        }
    }
    return count;
}

//
// ==============================================
int IsEmpty(Stack* *pStack){
    int flag;
    if((*pStack)->link==NULL){
        flag = 1;
    }else{
        flag = 0;
    }

    return flag;
}

//
// ==============================================
void reverse(linkedlist* *pHead, int Knum){
    linkedlist *i;
    Stack *mystack, *mystack2;
    linkedlist *item;
    int count;
    // use 2 stacks to store node in right ordered linkedlist
    // if stack1 is full, pop and print; else pop and push to 
    // (another) stack2, then pop and print (stack2)
    mystack = MakeStack();
    mystack2 = MakeStack();
    for (i = (*pHead); i; i = i->link){
        count = CountStack(&mystack);
        if (count == Knum){
            while(IsEmpty(&mystack)==0){
                item = Pop(&mystack);
                if(item->nextadd == -1){
                    printf("%05d %d %d\n",item->preadd,item->data,item->nextadd);
                }else{
                    printf("%05d %d %05d\n",item->preadd,item->data,item->nextadd);
                }  
            }
        }
        Push(&mystack, i);
    }

    if (CountStack(&mystack)==Knum){
        while(IsEmpty(&mystack)==0){
            item = Pop(&mystack);
            if(item->nextadd == -1){
                printf("%05d %d %d\n",item->preadd,item->data,item->nextadd);
            }else{
                printf("%05d %d %05d\n",item->preadd,item->data,item->nextadd);
            }  
        }
    }else{
        while(IsEmpty(&mystack)==0){
            item = Pop(&mystack);
            Push(&mystack2, item);
        }

        while(IsEmpty(&mystack2)==0){
            item = Pop(&mystack2);
            if(item->nextadd == -1){
                printf("%05d %d %d\n",item->preadd,item->data,item->nextadd);
            }else{
                printf("%05d %d %05d\n",item->preadd,item->data,item->nextadd);
            }  
        }
    }
}