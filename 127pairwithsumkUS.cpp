#include<iostream>
#include<cstdlib>
#include <algorithm>
using namespace std;
int main()
{     
    system("cls");   
    int a[] = {10,14,14,15,6,8,8,9};       
    int size = sizeof(a) / sizeof(a[0]);
    int k = 16;

    int h = *max_element(a,a+size);             
    int H[h + 1] = {0};

    for (int i = 0; i < size; i++) {
        if(H[k-a[i]] != 0) {
            cout << a[i] << k-a[i] << k << endl;
        }
        H[a[i]]++;
    }
    
    return 1;
}