#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){   
    
    int num, i;
    scanf("%d\n", &num);
    printf("num:%d\n", num);

    for (i = 0; i < num; i++){
        char data,l,r;
        printf("i:%d\n", i);
        scanf("%c %c %c\n",&data, &l, &r);
        
        printf("node:%c\n", data);
        printf("left:%c\n", l);
        printf("right:%c\n", r);
    }

    return 0;
}