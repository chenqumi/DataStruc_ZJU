#include <stdio.h>
#include <stdlib.h>

//
//====================================
typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct _list
{
    Node *head;
    //Node *tail;
} List;

void add(Node *head, int number);

//
//====================================
int main(int argc, char const *argv[])
{
    List list;
    int number;
    list.head = NULL;
    //list.tail = NULL;
    scanf("%d", &number);
    if (number != -1){
        add(&List, number);
    }
    return 0;
}

//
//====================================
void add(List *pList, int number)
{
    // add to linked-list
    Node *p = (Node*)malloc(sizeof(Node));
    p -> value = number;
    p -> next = NULL;
    // find the last
    Node *last = pList -> head;
        
    if (last){
        while(last -> next){
            last = last -> next;
        }
        last -> next = p;
    }else{
        pList -> head = p;
    }
}
