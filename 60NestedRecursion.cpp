#include <iostream>
#include <cstdlib>
using namespace std;

int fun(int n) {
    if (n>100) return n-10;
    else return fun(fun(n+11));
} 
//recusive call itself and passed the recursive funtion as a parameter
int main() {
    system("cls");
    cout << fun(95);
    return 0;
}
