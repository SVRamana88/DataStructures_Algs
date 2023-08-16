#include<iostream>
#include<stdlib.h>
using namespace std;

//recursive call made mutilple times in a singel recursive call

void fun(int n) {
   if (n>0) {
    cout << n << endl;
    fun(n-1); 
    fun(n-1);
   } 
}
int main() {
    system("cls");
   fun(3);
}