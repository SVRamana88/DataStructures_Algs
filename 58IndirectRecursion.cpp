#include <iostream>
#include <cstdlib>
using namespace std;
void funB(int n);
void funA(int n) {
    if (n>0) {
        cout << n << endl;
        funB(n-1);
    }
}
void funB(int n) {
    if (n>0) {
        cout << n << endl;
        funA(n/2);
    }
}

//funtions calls itself through one or more intermediate calls
int main() {
    system("cls");
    funA(20);
    return 0;
}
