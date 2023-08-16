#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
    system("cls");
    int **p = new int *[3];  // int **p = (int **)malloc(3*sizeof(int *));
    p[0] = new int[4];       // p[0] = (int *)malloc(4*sizeof(int));
    p[1] = new int[4];
    p[2] = new int[4];

    for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) 
            cout << p[i][j] << " ";//garbages
        cout << endl;
    }
    return 0;
}
