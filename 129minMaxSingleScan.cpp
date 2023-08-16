/*
#include <algorithm>
std::minmax_element(A, A+size);
minElement = *result.first;
maxElement = *result.second;
*/


#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{     
    system("cls");   
    int a[] = {6,8,8,9,10,14,14,15};       
    int size = sizeof(a) / sizeof(a[0]);
    int mi = a[0];
    int ma = a[0];
    for (int i = 0; i < size; i++)
    {
        if(mi > a[i]) mi = a[i];
        else if(ma < a[i]) ma = a[i];
    }
    cout << mi << ma;
    return 1;
}