#include<iostream>
#include<cstdlib>
using namespace std;

class DiagonalMatrix
{
private:
    int *M;
    int n;
public:
    DiagonalMatrix(int n);
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~DiagonalMatrix();
};

DiagonalMatrix::DiagonalMatrix(int n)
{
    this->n = n;
    M = new int[n];
}

void DiagonalMatrix::set(int i,int j,int x) {
    if (i == j) M[i] = x;

    /*
    void DiagonalMatrix::set(int i, int j, int x) {
    if (i >= 0 && i < n && j >= 0 && j < n && i == j) {
        M[i] = x;
    } else {
        cout << "Error: Invalid indices or not a diagonal element." << endl;
    }
    }
    */

}

int DiagonalMatrix::get(int i,int j) {
    if( i == j) return M[i];
    else return 0;
}

void DiagonalMatrix::display() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) cout << M[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    
}

DiagonalMatrix::~DiagonalMatrix()
{
    delete []M;
}


int main()
{
    system("cls");
    DiagonalMatrix   DM(3);
    DM.set(0,0,8);
    DM.set(1,1,8);
    DM.set(2,2,8);
    
    DM.display();
    return 0;
}
