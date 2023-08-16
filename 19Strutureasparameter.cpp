#include<iostream>
#include<cstdlib>
using namespace std;

struct Rectangle
{
    int l,b;
};

struct Triangle
{
    int l,b,h;
};

struct AasPinStruct
{
    int a[5];
    int n;
};



int area_callbyvalue(Rectangle r1) {     
    return r1.l * r1.b;
}

void lengthincrese_callbyaddress(Rectangle *r) {        //callbyreferece(Rectangle &r)  and r.l+=10
    r->l+=10;
}

Triangle * fun() {
    Triangle *p = new Triangle;
    p->l= 5;
    p->b=20;
    p->h=77;
    return p;
}

void fun2(AasPinStruct aps , int n) { //void fun2(AasPinStruct &aps , int n) array call by address and refrence is not posible
    for (int i = 0; i < n; i++)
    {
        cout << aps.a[i] << endl;
    }
   // aps.a[4]=66; no reflection because it is only possible send aryy inside struct with call by value only;
}


int main() {
    system("cls");
    Rectangle r = {4,5};
    cout << "Area : " << area_callbyvalue(r) << endl;
    lengthincrese_callbyaddress(&r);                   //callbyreferece(r);
    cout << "new length : " << r.l << endl;


    Triangle *tptr = fun();
    cout << "Trianle dimensions : " << tptr->l << tptr->b << tptr->h << endl;


    AasPinStruct aps = {{1,2,3,4,5} , 5};
    fun2(aps , 5);
    //aps.a[4]; 
    
}