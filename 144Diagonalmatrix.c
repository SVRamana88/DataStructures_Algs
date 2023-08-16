#include<stdio.h>
#include<stdlib.h>
struct Diagonal
{
    int n;
    int A[5];
};

void set(struct Diagonal *M,int i,int j,int x) {
    if (i==j) {
        M->A[i] = x;
    }
}

int get(struct Diagonal M,int i,int j) {
    if(i==j) {
        return M.A[i];
    }
    else {
        return 0;
    }
}

void display(struct Diagonal M) {
    int i,j;
    for ( i = 0; i < M.n ; i++)
    {
       for ( j = 0; j < M.n; j++)
       {
        if(i==j) printf("%d ",M.A[i]);
        else printf("0 ");
       }
       printf("\n");
    } 
}

void display2(struct Diagonal M) {
    int i;
    for ( i = 0; i < M.n ; i++)
    {
       printf("%d ",M.A[i]);
    } 
}

int main()
{
    system("cls");
    struct Diagonal M;
    M.n = 3;
    set(&M,0,0,8);
    set(&M,1,1,8);
    set(&M,2,2,8);
    set(&M,9,9,9);
    printf("%d\n",get(M,0,0));
    display(M);
    display2(M);
    return 0;
}
