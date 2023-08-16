#include<iostream>
#include<cstdlib>
using namespace std;

void p(char s[] , int k ) {

    static int  memory[10];
    static char result[10];

    if( s[k] =='\0') {
        result[k] = '\0';
        cout << result << endl;
    }

    else{
        for(int i=0;s[i]!='\0';i++) {
            if(memory[i] == 0) {
                memory[i] = 1;
                result[k] = s[i];
                p(s,k+1); 
                memory[i] = 0; //backtrack
            }
        }
    }

}

int main()
{
    system("cls");
    char s[] = "ABC";
    p(s,0);
    return 0;
}

/*
#include <iostream>
#include <cstdlib>
using namespace std;

// Function to generate permutations of a string
// s: the input string to be permuted
// k: the current index being considered for permutations
// memory: an array to keep track of characters used in current permutation
// result: an array to store the current permutation being formed
void p(char s[], int k, int memory[], char result[]) {
    if (s[k] == '\0') {
        cout << result << endl; // Print the current permutation when the end of string is reached
    } else {
        for (int i = 0; s[i] != '\0'; i++) {
            if (memory[i] == 0) { // Check if the character is not used in the current permutation
                memory[i] = 1; // Mark the character as used in the current permutation
                result[k] = s[i]; // Add the character to the current permutation
                p(s, k + 1, memory, result); // Recursive call for the next index
                memory[i] = 0; // Backtrack: Mark the character as unused to explore other permutations
            }
        }
    }
}

// Wrapper function to initiate the permutation process
void permuteString(char s[]) {
    // Create an array to keep track of characters used in the permutation
    int memory[10] = {0};
    
    // Create an array to store the current permutation being formed
    char result[10] = {0};
    
    // Start generating permutations from the first index (k = 0)
    p(s, 0, memory, result);
}

int main() {
    system("cls");
    char s[] = "ABC";
    permuteString(s); // Call the wrapper function to start the permutation process
    return 0;
}

*/
