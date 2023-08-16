#include<iostream>
#include<cstdlib>
using namespace std;
class Element
{
    public:
        int i;
        int j;
        int x;
};

class SparseMatrix
{
private:
    int m;
    int n;
    int num;
    Element *ele;
public:
    void create();
    void display();
    SparseMatrix  add(SparseMatrix s2);
};

void SparseMatrix::create() {
    cout << "Enter Dimensions : ";
    cin >> m >> n;
    cout << "No of NON ZERO elements : ";
    cin >> num;
    ele = new Element[num];
    cout << "Enter ele i j :";
    for (int i = 0; i < num ; i++)
    {
        cin >> ele[i].x >> ele[i].i >> ele[i].j; //since ele member of same class it directly access
    }  
}

void SparseMatrix::display() {
    cout << "\n displaying : \n";
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == ele[k].i && j == ele[k].j)  {
                cout << ele[k++].x << " "; 
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

SparseMatrix  SparseMatrix::add(SparseMatrix s2) {
    cout << "Addition : ";
    int i=0,j=0,k=0;
    SparseMatrix sum =  SparseMatrix(); //calling constuctor to crate new object
    sum.ele = new Element[num + s2.num];
    while (i < num && j < s2.num)
    {
        if (ele[i].i < s2.ele[j].i) {
            sum.ele[k++] = ele[i++];
        }
        else if(ele[i].i > s2.ele[j].i) {
            sum.ele[k++] = ele[j++];
        }
        else {
            if (ele[i].j < s2.ele[j].j) {
            sum.ele[k++] = ele[i++];
            }
            else if(ele[i].j > s2.ele[j].j) {
            sum.ele[k++] = ele[j++];
            }
            else {
                sum.ele[k] = ele[i];
                sum.ele[k++].x = ele[i++].x + s2.ele[j++].x;
            }
        }
    }
    for(;i<num;i++) sum.ele[k++] = ele[i];
    for(;j<s2.num;j++) sum.ele[k++] = ele[i];
    sum.m = m;
    sum.n = n;
    sum.num = k;
    return sum;
}


int main()
{
    system("cls");
    SparseMatrix s1,s2,sum;
    s1.create();
    s1.display();
    s2.create();
    s2.display();
    sum = s1.add(s2);
    sum.display();
    return 0;
}

