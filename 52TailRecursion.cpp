#include<iostream>
#include<stdlib.h>
using namespace std;



void fun(int n) {
   if (n>0) {
    cout << n << endl;
    fun(n-1); //return time do nothing
   } 
}
int main() {
    system("cls");
    fun(3); 
}