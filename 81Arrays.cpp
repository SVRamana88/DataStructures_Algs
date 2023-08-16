#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
    system("cls");
    int a[5] = {3,5,5,3,2};
    for(int i:a) {
        cout << i << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << &i[a] << endl;
    }

    cout << "jjjjjjjjjjjjjjjjjjjjjjjj" << endl;
    int *ptr = a;
    cout << ptr << endl;
    cout << ptr++ << endl;
    cout << ptr << endl;
    cout << ptr + 1 << endl;
    cout << ptr << endl;
    


    return 0;
}
