#include <stdio.h>
#include <stdlib.h>

typedef struct _poly{
    int coef;
    int expon;
    struct _poly *next;
} polynomial;

polynomial* ReadPoly();
void Attach(int c, int e, polynomial* *pRear);
void Mult(polynomial* *ppoly1, polynomial* *ppoly2);

int main(int argc, char const *argv[]){
    
    polynomial *poly1, *poly2;

    poly1 = ReadPoly();
    poly2 = ReadPoly();
    Mult(&poly1, &poly2);

    return 0;

}

polynomial* ReadPoly(){
    
    int n;
    polynomial *Head, *Rear, *t;
    /* Head have to be initialized, */
    /* present an empty node */
    Head = (polynomial*)malloc(sizeof(polynomial));
    Head->next = NULL;
    Rear = Head;

    scanf("%d",&n);
    while(n--){
        int c, e;
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    /* free the empty Head node*/
    t = Head;
    Head = Head->next;
    free(t);

    return Head;

}

void Attach(int c, int e, polynomial* *pRear){
    
    polynomial *p;
    p = (polynomial*)malloc(sizeof(polynomial));
    p->coef = c;
    p->expon = e;
    p->next = NULL;
    /* attach p to Rear, and move Rear to p */
    (*pRear)->next = p;
    *pRear = p;

}

void Mult(polynomial* *ppoly1, polynomial* *ppoly2){
    
    int c, e;
    polynomial *multi, *Rear, *i, *j, *t;
    polynomial *k;
    multi = (polynomial*)malloc(sizeof(polynomial));
    multi->next = NULL;
    //Rear = multi;

    for(i = *ppoly1; i; i = i->next){
        for(j = *ppoly2; j; j = j->next){
            c = (i->coef)*(j->coef);
            e = (i->expon)+(j->expon);

            Rear = multi;
            /* find insert position*/
            while(Rear->next && Rear->next->expon > e){
                Rear = Rear->next;
            }
            /*according to e do somnething*/
            if(Rear->next && Rear->next->expon == e){
                if(Rear->next->coef + c){
                    Rear->next->coef += c;
                }else{
                    t = Rear->next;
                    Rear->next = t->next;
                    free(t);
                }
            }else{
                t = (polynomial*)malloc(sizeof(polynomial));
                t->coef = c;
                t->expon = e;
                
                t->next = Rear->next;
                Rear->next = t;
            }
        }
    }
    t = multi;
    multi = multi->next;
    free(t);

    for(k = multi; k; k = k->next){
        printf("co: %d\n", k->coef);
        printf("ex: %d\n", k->expon);
    }
}