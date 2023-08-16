#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    system("cls");
    char s[] = "abca";
    int H[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        if((s[i] - 'a') > 0) {
            cout << "contains duplicates" << endl; 
            cout << s[i];
            break;
        }
        else {
            H[i] = 1;
        }
    }
    
    return 0;
}
