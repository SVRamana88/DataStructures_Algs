#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{     
    system("cls");   
    int a[] = {6,8,8,9,10,14,14,15};       
    int size = sizeof(a) / sizeof(a[0]);
    int k=16;
    int i=0,j=size-1;
    while (i<j)
    {
        int s = a[i] + a[j];
        if(s == k ) {
            cout << a[i] << a[j] << k << endl;
            i++;
            j--;
        }
        else if (s<k) {
            i++;
        }
        else {
            j--;
        }
    }
    

    return 1;
}