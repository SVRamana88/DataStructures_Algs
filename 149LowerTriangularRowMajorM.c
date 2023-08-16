#include<stdio.h>
#include<stdlib.h>
struct LowerTriangle
{
    int n;
    int *A;
};

void set(struct LowerTriangle *M,int i,int j,int x) {
    if (i>=j) {
        M->A[( (i*(i-1)/2) + j-1)]=x;
    }
}

int get(struct LowerTriangle M,int i,int j) {
    if(i>=j) {
        return M.A[((i*(i-1)/2) + j-1)];
    }
    else {
        return 0;
    }
}

void display(struct LowerTriangle M) {
    int i,j;
    for ( i = 1; i <= M.n ; i++)
    {
       for ( j = 1; j <= M.n; j++)
       {
        if(i>=j) printf("%d ",M.A[((i*(i-1)/2) + j-1)]);
        else printf("0 ");
       }
       printf("\n");
    } 
}


int main()
{
    system("cls");
    int i,j;
    int x;
    struct LowerTriangle M;
    M.n = 3;
    M.A = (int *)malloc((M.n * ( M.n + 1 ) / 2 )  * sizeof(int ));
    printf("Enter elements :\n");
    for ( i = 1; i <= M.n; i++)
    {
        for ( j = 1; j <= M.n; j++)
        {
            scanf("%d",&x);
            set(&M,i,j,x);
        }
    }
    
    display(M);
    return 0;
}
