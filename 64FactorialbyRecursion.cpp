#include <iostream>
#include <cstdlib>
using namespace std;

int fact(int n) {
    if (n < 0) return -1;
    if (n==0) return 1;
    else return fact(n-1) * n;
}
int main() {
    system("cls");
    cout << fact(8);
    return 0;
}
