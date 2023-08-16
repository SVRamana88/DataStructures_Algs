// #include <iostream>
// #include <cstdlib>
// using namespace std;

// // Swap function for characters
// void swap(char &a, char &b) {
//     char t = a;
//     a = b;
//     b = t;
// }

// void p(char s[], int low) {
//     if (s[low] == '\0') {
//         cout << s << endl;
//     } else {
//         for (int i = low; s[i] != '\0'; i++) {
//             swap(s[low], s[i]); // Swap characters in the array
//             p(s, low + 1);      // Recursive call for the next character
//             swap(s[low], s[i]); // Backtrack to original state
//         }
//     }
// }

// int main() {
//     system("cls");
//     char s[] = "ABC";
//     p(s, 0);
//     return 0;
// }



// /*

// call by pointer


// t = s[low]; 
// s[low] = s[i];
// s[i] = t;



// void swap(char *s ,int low, int i) {
//     char t;
//     t = s[low];
//     s[low] = s[i];
//     s[i] = t;
// }


// */



#include <iostream>
#include <string>
#include <algorithm> // for std::swap
using namespace std;

// Function to generate permutations of a string
// s: the input string to be permuted
// low: the starting index for generating permutations
void p(string s, int low) {
    // If we have reached the end of the string, print the current permutation
    if (low == s.length() - 1) {
        cout << s << endl;
    } else {
        // Loop through the remaining characters in the string
        for (int i = low; i < s.length(); i++) {
            // Swap the characters at indices 'low' and 'i'
            swap(s[low], s[i]);
            
            // Recursively generate permutations for the remaining characters
            p(s, low + 1);
            
            // Backtrack: Undo the previous swap to explore other permutations
            swap(s[low], s[i]);
        }
    }
}

int main() {
    // Input string to permute
    string s = "ABC";
    
    // Call the permutation function with the initial index 0
    p(s, 0);
    
    return 0;
}











/*#include <iostream>
#include<algorithm>
using namespace std;

template <typename T>
class permute
{
public:
    void p(T s[],int low,int size0);
};

template <typename T>
void permute<T>::p(T s[], int low,int size) {
    if (low == size) {
        for (int i = 0; i < size; i++) {
            std::cout << s[i] << " ";
        }
        std::cout << std::endl;
        //std::cout << s << std::endl;     for sting only hence end of string is "\0" 
    } else {
        for (int i = low;i < size; i++) {
            swap(s[low], s[i]); // Swap characters in the array
            p(s, low + 1,size);      // Recursive call for the next character
            swap(s[low], s[i]); // Backtrack to the original state
        }
    }
}



int main() {
    char s[] = "ABC";
    permute<char> t;
    t.p(s,0,3);

    return 0;
}




// template <typename T>
// void swap(T &a, T &b) {
//     T t = a;
//     a = b;
//     b = t;
// }



*/