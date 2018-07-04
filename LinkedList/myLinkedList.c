#include <stdio.h>
#include <stdlib.h>

//
//=====================================
typedef struct _node
{
    int value;
    struct _node* next;
} Node;

void add(Node* head, int number);

//
//=====================================
int main(int argc, char const *argv[])
{
    int number;
    Node* head = NULL; // head amount to the linked-list(variable name)

    while(number != -1)
    {    
        scanf("%d",&number);

        if (number != -1)
        {
            add(head, number); // params is "head", not "*head"
        }
    }
    
    return 0;
}

//
//=====================================
void add(Node* head, int number)
{
    // add to linked-list
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    // find the last
    Node* last = head;

    if (last == NULL) // last is the head,means last is NULL
    {   
        head = p;

    }else{

        while(last->next != NULL)
        {
            last = last->next;
        }
        // attach to linked-list
        last->next = p;
    }
}