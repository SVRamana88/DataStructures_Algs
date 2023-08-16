#include<iostream>
#include<cstdlib>
using namespace std;

class LowerTriangleMatrix
{
private:
    int *A;
    int n;
public:
    LowerTriangleMatrix(int n);
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~LowerTriangleMatrix();
};

LowerTriangleMatrix::LowerTriangleMatrix(int n)
{
    this->n = n;
    A = new int[n * (n + 1) / 2];
}

void LowerTriangleMatrix::set(int i,int j,int x) {
    if (i >= j) A[((i*(i-1)/2) + j-1)] = x;
}

int LowerTriangleMatrix::get(int i,int j) {
    if( i >= j) return A[((i*(i-1)/2) + j-1)];
    else return 0;
}

void LowerTriangleMatrix::display() {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i>=j) cout << A[((i*(i-1)/2) + j-1)] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    
}

LowerTriangleMatrix::~LowerTriangleMatrix()
{
    delete []A;
}


int main()
{
    system("cls");
    int size;
    cout << "enter size :";
    cin >>  size;
    LowerTriangleMatrix   m(size);
    printf("Enter elements :\n");
    for ( int  i = 1; i <= size; i++)
    {
        for ( int j = 1; j <= size; j++)
        {
            int x;
            scanf("%d",&x);
            m.set(i,j,x);
        }
    }
    m.display();
    return 0;
}
