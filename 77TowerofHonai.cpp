#include <iostream>
#include <cstdlib>
using namespace std;

void towers_of_hanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << src << " to " << dest << endl;
        return;
    }

    towers_of_hanoi(n-1, src, aux, dest);
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    towers_of_hanoi(n-1, aux, dest, src);
}

int main() {
    system("cls");
    int n = 3;  // Number of disks
    char src = 'A';
    char dest = 'C';
    char aux = 'B';

    towers_of_hanoi(n, src, dest, aux);

    return 0;
}
