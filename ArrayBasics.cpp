#include<iostream>
using namespace std;

int main() {

    int A[5] = {1,2,3}; //INITIALIZED  ARRAY : unasigned values = 0

    for(int x: A) {
        cout << x << endl;
    }

    int n;
    cout << "Enter n value :";
    cin >> n;
    int B[n] ;         // VARIBLE SIZED ARRAY : unasigned  vlaues = garbage values (one  of then may be 0 its also a garbage)
    B[0] = 2;
    B[1] = 5;

    for(int x: B) {
        cout << x << endl;
    }
    
    return 0;

}