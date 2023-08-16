#include<iostream>
#include<stdlib.h>
using namespace std;

// int* fun()
// {
//     int *p = new int[5];          //int * p = (int *)malloc(sizeof(5 * size of(int));
//     return p;
// }

// int main()
// { 
//     system("cls");
//     int *mp = fun();
//     for (int i = 0; i < 5; i++)
//     {
//         cout << *(mp + i) << endl;
//     }
//     return 0;
// }


void  fun(int a[] , int n)  {              //fun(int *a , int n)         
    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << endl;
        a[i] ++;
    }

     cout << "size : " << sizeof(a) << endl;

}
int main () {
    system("cls");
    int a[5] = {2,4,5,8,9};
    fun(a,5);
    for (int i = 0; i < 5; i++) 
    {
        cout << a[i] << endl;
    }
    cout << "size : " << sizeof(a) << endl;
}