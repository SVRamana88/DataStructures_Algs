#include<iostream>
#include<stdlib.h>
using namespace std;

//int x = 0;

int fun(int n) {
    static int x = 0;
    if (n>0) {
        x++;
        return fun(n-1) + x;      // first  evaluate fun(n-1) then go to x and grab x value then sum perform
    }
    return 0;
}
int main() {
    system("cls");
    cout << fun(5); //25
}