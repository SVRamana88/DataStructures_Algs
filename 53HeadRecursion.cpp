#include<iostream>
#include<stdlib.h>
using namespace std;



void fun(int n) {
   if (n>0) {
    fun(n-1); //calling time do nothing
    cout << n << endl;
   } 
}
int main() {
    system("cls");
   fun(3);
}