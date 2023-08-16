#include <iostream>
#include <cstdlib>
using namespace std;

int power(int m,int n) {
    if (n==0) return 1;
    return power(m,n-1) * m;
}

int optimalpower(int m, int n) { //here total multiplications reduced
    if (n==0) return 1;
    if(n%2==0) return optimalpower(m*m, n/2);
    else return m* optimalpower(m*m,(n-1)/2);
}

int main() {
    system("cls");
    cout << power(2,3) << endl;
    cout << optimalpower(2,3) << endl;
    return 0;
}
