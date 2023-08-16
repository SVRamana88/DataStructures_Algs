#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    system("cls");
    char s[] = "finding";
    long int H=0,t=0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        t = (1 << s[i] - 'a'); //s[i] - 97 // Set the bit corresponding to the character position in the alphabet
        if(t & H) {      
           cout << s[i] << " dupicate" << endl;
        }
        else { 
            H |= t; // Set the corresponding bit in H to mark the character as visited
        }
    }
    
    return 0;
}
