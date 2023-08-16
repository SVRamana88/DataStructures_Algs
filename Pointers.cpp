#include<iostream>
#include<stdlib.h>
using namespace std;

struct stpointer
{
    int a;
    char b;
};


int main() {

    // int n = 8;
    // int *p = &n;                     // normal pointer
    // cout << *p;             

    system("cls");
    int n =  8;
    void *p = &n;
    cout << *(int *)p << endl;         //void pointer

    int a[5] = {22,54,566};      //not allocated in heap it is allocated at stack frame

    /*
    c syntax
    #include< stdlib>   allocating memeory in heap
    int *ptr = (int *) malloc(5 * sizeof(int));
    ptr[0]= 1;ptr[2]=8.....               // in case of arrays pointer act as a name of an array

    free(ptr) // c syntax
    */


    int *ap = a;                       // a itself is a starting address of an array
    cout << a << endl;   

    for (int i = 0; i<3 ; i++) {  
        cout << *(ap + i) << endl;     // pointer arthematic
    }
    for (int i = 0; i<3 ; i++) {  
        cout << ap[i] << endl;         // in case of arrays pointer act as a name of an array
    }



    



    int *h = new int[5];             // allocating memeory in heap
    h[0]=500000;
    for (int i = 0; i<5 ; i++) {  
        cout << h[i] << endl;         // in case of arrays pointer act as a name of an array
    }
    delete []h;   // in cpp for deleting arry u must specify [] (subscripsts)
    



    cout << "        sizes        " << endl;

    int *l;                     
    struct stpointer stp;
    double *dd;
    char *chr;
    cout << sizeof(l) << endl;
    cout << sizeof(stp) << endl;
    cout << sizeof(dd) << endl;
    cout << sizeof(chr) << endl;        //size of pointer is always same irrective of datatype except struct


    //every pointer takes same size
    
}



