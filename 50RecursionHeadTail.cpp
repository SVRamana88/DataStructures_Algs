#include<iostream>
#include<cstdlib>
using namespace std;

void fun(int n) {
    
    if (n>0) {
        cout << n << endl;
        fun(n-1);
        cout << n << endl;
    }
}

int main() {
    system("cls");
    fun(3);
}