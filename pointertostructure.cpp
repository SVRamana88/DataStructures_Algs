#include<iostream>
#include<stdlib.h>
using namespace std;

struct Rectangel
{
    int l,b;
    double c;
};


int main() {
    system("cls");
    Rectangel *rp = new Rectangel;          // new used create obj in heap
    rp->l= 6;
    rp->b = 6;
    cout << "length : " << rp->l << endl;   //(*rp).l;
    cout << "breadth : " << rp->l << endl;   //(*rp).b;
    cout << sizeof(rp); //4
}