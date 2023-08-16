#include <iostream>
#include <cstdlib>
using namespace std;
int F[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; //memorization purpose

int fib(int n) {
    if (n<=1) return n;
    return fib(n-2) + fib(n-1);  //O(2^n)
}

int mfib(int n) {
    if (n<=1) {
        F[n] = n;
        return n;
    }
    else {
        if (F[n-2] == -1) F[n-2] = mfib(n-2);
        if (F[n-1] == -1) F[n-1] = mfib(n-1);
        return  F[n-2] + F[n-1];           //O(n)
    }
}


int main() {
    system("cls");
    cout << fib(4) << endl;
    cout << mfib(4) << endl;
    return 0;
}
