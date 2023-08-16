#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
class Term
{
    public:
        int coff;
        int Expo;
};

class Polynomial
{
private:
    int n;
    Term *ele;
public:
    void create();
    int compute(int x);
    Polynomial  add(Polynomial s2);
};

void Polynomial::create() {
    cout << "Enter Terms : ";
    cin >> n;
    ele = new Term[n];
    cout << "\ncoff and expo : ";
    for (int i = 0; i < n ; i++)
    {
        cin >> ele[i].coff >> ele[i].Expo ; //since ele member of same class it directly access
    }  
}

int Polynomial::compute(int x) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=(ele[i].coff * pow(x ,ele[i].Expo));
    }
    return sum;
}

Polynomial Polynomial::add(Polynomial p) {
    cout << "\n additon : \n";

    Polynomial s = Polynomial();
    s.ele = new Term[n+p.n];

    int i=0,j=0,k = 0;
    while (i<n && j<p.n)
    {
        if (ele[i].Expo == p.ele[j].Expo) {
            s.ele[k].Expo = ele[i].Expo;
            s.ele[k].coff = ele[i].coff + p.ele[k].coff;
            k++;
            i++;
            j++;
        }
        else if(ele[i].Expo > p.ele[j].Expo) {
            s.ele[k++] = ele[i++];
        }
        else {
            s.ele[k++] = p.ele[j++];
        }
    }
    for(;i<n;i++) s.ele[k++] = ele[i];
    for(;j<n;j++) s.ele[k++] = ele[j];
    s.n = k;
    return s;
}


int main()
{
    system("cls");
    Polynomial p1,p2,sum;
    p1.create();
    
    cout << p1.compute(1);
    p2.create();
    sum = p1.add(p2);
    cout << sum.compute(1);
    return 0;
}

