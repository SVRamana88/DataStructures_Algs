#include<iostream>
#include<cstdlib>
using namespace std;

struct Rectangle
{
    int l,b;     //default public inside struct

    // void inilize(int a,int c) {
    //     l=a;
    //     b=c;
    // }

    int area() {
        return l*b;
    }

};

int main() {
    system("cls");
    Rectangle r = {3,5};
    //r.inilize(3,5);
    cout << "Area : " << r.area() << endl;
}


// class Rectangle
// {
//     public:

//     int l,b;     //default private inside class

//     void inilize(int a,int c) {
//         l=a;
//         b=c;
//     }

//     int area() {
//         return l*b;
//     }

// };

// int main() {
//     system("cls");
//     Rectangle r;
//     r.inilize(3,5);
//     cout << "Area : " << r.area() << endl;
// }