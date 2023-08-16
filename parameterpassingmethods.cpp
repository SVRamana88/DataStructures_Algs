#include<iostream>
#include<stdlib.h>
using namespace std;

void swappassbyvalue(int x,int y) {
    int t;
    t = x;
    x = y;
    y = t;

    cout << " x : " << x << endl;
    cout << " y : " << y << endl;
}

void swappassbyaddress(int *x,int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;

    cout << " x : " << *x << endl;
    cout << " y : " << *y << endl;
}

void swappassbyreference(int& x,int &y) {         // int &x = a and int &y = b;
    int t;
    t = x;
    x = y;
    y = t;


    cout << " x : " << x << endl;
    cout << " y : " << y << endl;
}

void increbyrefe(int &x) {
    x+=88;
}

int main() {
    system("cls");
    int a=10,b=20;
    cout << " a : " << a << endl;
    cout << " b : " << b << endl;
    swappassbyvalue(a,b);
    cout << " a : " << a << endl;
    cout << " b : " << b << endl;
    swappassbyaddress(&a,&b);
    cout << " a : " << a << endl;
    cout << " b : " << b << endl;
    swappassbyreference(a,b);
    cout << " a : " << a << endl;
    cout << " b : " << b << endl;


    increbyrefe(a);
    cout << " a : " << a << endl;

    // x+=34;
    // cout << " a : " << a << endl;      error: 'x' was not declared in this scope      



}


//void swappassbyvalue(int &x,int y) {
//void swappassbyvalue(int *x,int y) { void swappassbyvalue(int &x,int *y) {  all works