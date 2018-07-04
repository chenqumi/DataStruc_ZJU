#include <stdio.h>
#include <stdlib.h>

//
//=====================================
typedef struct _node
{
    int value;
    struct _node* next;
} Node;


//
//=====================================
typedef struct _list
{
    Node* head;
    // Node* tail;
} List;


//
//=====================================
void add(List* pList, int number);
void traversal(List* pList);

int main(int argc, char const *argv[])
{
    int number;
    //Node* head = NULL; // head amount to the linked-list(variable name)
    List list;
    list.head = NULL;
    // list.tail = NULL;
    while(number != -1)
    {
        scanf("%d",&number);

        if (number != -1)
        {
            add(&list, number); // params is "head", not "*head"
        }
    }
    
    traversal(&list);

    return 0;
}

//
//=====================================
void add(List* pList, int number)
{
    // add to linked-list
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    // find the last
    Node* last = pList->head;

    if (last != NULL) // last is the head,means last is NULL
    {   
        while(last->next != NULL)
        {
            last = last->next;
        }
        // attach to linked-list
        last->next = p;

    }else{

        pList->head = p;
    }

}

void traversal(List* pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%d\t",p->value);
    }
    printf("\n");
}