#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define Null -1
/*
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
*/

struct TreeNode{
    char node;
    int left;
    int right;
} T1[MAXSIZE],T2[MAXSIZE];


int MakeTree(struct TreeNode T[]);
int IsIsomorphic(int R1, int R2);

int main(int argc, char const *argv[]){
    
    int R1,R2;

    R1 = MakeTree(T1);
    // for (i = 0; i < 8; i++){
    //     printf("node:%c\n", T1[i].node);
    //     printf("left:%d\n", T1[i].left);
    //     printf("right:%d\n", T1[i].right);
    // }
    R2 = MakeTree(T2);
    if (IsIsomorphic(R1, R2)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;

}

int MakeTree(struct TreeNode T[]){

    int num, i, Root;
    char data, l, r;
    scanf("%d\n", &num);
    int check[num];

    if(num){
        for (i = 0; i < num; i++){
            check[i] = 0;
        }

        for (i = 0; i < num; i++){

            scanf("%c %c %c\n",&data, &l, &r);
            T[i].node = data;
            T[i].left = l;
            T[i].right = r;

            if (l != '-'){
                T[i].left = l - '0';
                check[T[i].left] = 1;
            }else{
                T[i].left = Null;
            }

            if (r != '-'){
                T[i].right = r - '0';
                check[T[i].right] = 1;
            }else{
                T[i].right = Null;
            }
        }

        for (i = 0; i < num; i++){
            if (!check[i]){
                break;
            }
        }
        Root = i;
    }else{
        Root = -1;
    }


    return Root;
    
}

int IsIsomorphic(int R1, int R2){
    
    if (R1==Null && R2==Null){
        return 1;
    }else if((R1==Null && R2!=Null) || (R1!=Null && R2==Null)){
        return 0;
    }else if(T1[R1].node != T2[R2].node){
        return 0;
    }else if(T1[R1].left==Null && T2[R2].left==Null){
        return IsIsomorphic(T1[R1].right, T2[R2].right);
    }else if( (T1[R1].left!=Null && T2[R2].left!=Null) &&
    (T1[T1[R1].left].node==T2[T2[R2].left].node) ){
        return(IsIsomorphic(T1[R1].left, T2[R2].left) && IsIsomorphic(T1[R1].right, T2[R2].right));
    }
    else{
        return (IsIsomorphic(T1[R1].left, T2[R2].right) && IsIsomorphic(T1[R1].right, T2[R2].left));
    }
}