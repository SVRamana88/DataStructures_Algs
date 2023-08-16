#include <iostream>
#include <cstdlib>
using namespace std;
//reduced multiplications
double e(double x, double n) {
    static double s = 1;
    
    if (n==0) return s;
    s = 1 + x/n * s;
    return e(x,n-1); 
}


int main() {
    system("cls");
    cout << e(2,7); //e(x,n)
    return 0;
}
