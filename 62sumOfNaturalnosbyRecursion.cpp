#include <iostream>
#include <cstdlib>
using namespace std;

int sum(int n) {
    if (n == 0) return 0;
    else return sum(n-1) + n;       //return n + sum(n-1); write like this tracing not comfortable
}

int main() {
    system("cls");
    cout << sum(8);
    return 0;
}
