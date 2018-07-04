#include <stdio.h>

int maxsum(int* p, int k);

int main()
{
    int k,i,number,result;
    scanf("%d",&k);
    int array[k];
    int *parray;


    for (i = 0; i < k; ++i){
        scanf("%d",&number);
        array[i] = number;
    }
    /* parray = &array will WARNING */
    parray = array;

    result = maxsum(parray,k);

    printf("%d\n", result);
    
    return 0;
}

int maxsum(int* p, int k)
{   
    int max = 0;
    int sum = 0;
    int i;

    for (i = 0; i < k; ++i){
        sum += p[i];
        
        if (sum < 0){
            sum = 0;
        }

        if (max < sum){
            max = sum;
        }
    }
    return max;
}