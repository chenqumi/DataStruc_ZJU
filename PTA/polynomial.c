#include <stdio.h>
#include <stdlib.h>

typedef struct _poly{
    int coef;
    int expon;
    struct _poly* next; 
} polynomial;


polynomial* ReadPloy();
void Attach(int c, int e, polynomial* *pRear);
void Mult(polynomial* *ppoly1, polynomial* *ppoly2);


int main(int argc, char const *argv[])
{   
    polynomial *poly1,*poly2;
    polynomial* i;
    
    poly1 = ReadPloy();
    poly2 = ReadPloy();

    Mult(&poly1, &poly2);
    return 0;
}

polynomial* ReadPloy(){
    int n;
    polynomial *head,*Rear,*t;

    scanf("%d",&n);
    head = (polynomial*)malloc(sizeof(polynomial));
    head->next = NULL;
    Rear = head;
    
    while(n--){
        int c,e;
        scanf("%d %d",&c,&e);
        Attach(c, e, &Rear);
    }
    t = head;
    head = head->next;
    free(t);

    return head;
}

void Attach(int c, int e, polynomial* *pRear){
    polynomial* p;
    p = (polynomial*)malloc(sizeof(polynomial));
    p->coef = c;
    p->expon = e;
    p->next = NULL;

    (*pRear)->next = p;
    *pRear = p;
}

void Mult(polynomial* *ppoly1, polynomial* *ppoly2){
    polynomial *multi,*i,*j,*k;
    polynomial *t;
    polynomial* Rear;
    int co,ex;

    multi = (polynomial*)malloc(sizeof(polynomial));
    multi->next = NULL;

    for (i = *ppoly1; i; i = i->next){
        
        for (j = *ppoly2; j; j = j->next){
            co = (i->coef) * (j->coef);
            ex = (i->expon) + (j->expon);
            polynomial* p;
            p = (polynomial*)malloc(sizeof(polynomial));
            p->coef = co;
            p->expon = ex;
            p->next = NULL;

            Rear = multi;

            while(Rear->next && p->expon < Rear->next->expon){
                Rear = Rear->next;
            }

            if(Rear->next && p->expon == Rear->next->expon){
                if(Rear->next->coef + p->coef){
                    Rear->next->coef += p->coef;
                }else{
                    t=Rear->next;
                    Rear->next = t->next;
                    free(t);
                }
            }else{
                t = (polynomial*)malloc(sizeof(polynomial));
                t->coef = p->coef;
                t->expon = p->expon;
                t->next = Rear->next;
                Rear->next = t;
                Rear = Rear->next;
                
                /* In my solution,t is just an empty pointer with no content */ 
                // t = Rear->next;
                // Rear->next = p;
                // p->next = t; 
            }
            //printf("Rear in loop :%p\n", Rear);
            //Rear = multi;
        }
    }

    t = multi;
    multi = multi->next;
    free(t);

    for (k = multi; k; k = k->next){
        printf("coef: %d\n", k->coef);
        printf("expon: %d\n", k->expon);
    }
}