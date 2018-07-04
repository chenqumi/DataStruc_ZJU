#include <stdio.h>

int maxsum(int* p, int k, int* phead, int* ptail);

int main()
{
    int k,i,number,result;
    scanf("%d",&k);
    int array[k];
    int* parray = NULL;
    int* phead = NULL;
    int* ptail = NULL;


    for (i = 0; i < k; ++i){
        scanf("%d",&number);
        array[i] = number;
    }
    /* parray = &array will WARNING*/
    parray = array;

    result = maxsum(parray,k,phead,ptail);

    printf("%d\n", result);
    
    return 0;
}

int maxsum(int* p, int k, int* phead, int* ptail)
{      
    int i;
    int max,sum,head,tail,maxhead,maxtail;
    max = sum = head = tail = maxhead = maxtail = 0;

    for (i = 0; i < k; ++i){
//================================
        if (sum == 0 && p[i] > 0){
            head = p[i];
            tail = p[i];
            //phead = &p[i];
        }

        sum += p[i];        
        
        if (sum < 0){
            sum = 0;
        }

        if (max < sum){
            max = sum;
            tail = p[i];
            maxhead = p[i];
            maxtail = p[i];
        }      
    }
    return max;
}