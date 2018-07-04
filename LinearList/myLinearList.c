#define MAXSIZE 100

typedef struct _llist
{
    int arr[MAXSIZE];
    int last;
} LinearList;

//
//==============================================

LinearList MakeEmpty();

int FinedKth(int k, LinearList *L);

//int Find(int element, LinearList *L);

//void Insert(int i, int element, LinearList *L);

//void Delete(int i LinearList *L);

//int Length(LinearList *L);

//
//==============================================
LinearList MakeEmpty()
{
    LinearList *L;

    L = (LinearList)malloc(sizeof(LinearList));
    L->last = -1;

    return L;
}

//
//==============================================
int FinedKth(int k, LinearList *L)
{
    return L->arr[k];   
}

//
//==============================================
int main()
{
    int i;
    MakeEmpty();
    i = FinedKth(3,L);
    printf("%d\n", i); 
    return 0;
}