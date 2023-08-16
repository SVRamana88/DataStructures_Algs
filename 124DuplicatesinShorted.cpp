#include<iostream>
#include<cstdlib>
#include <algorithm>
using namespace std;
int main()
{     
    system("cls");   
    int a[] = {6,8,8,9,10,14,14,15};       
    int size = sizeof(a) / sizeof(a[0]);

    //methods 1 best for shorted arrays
    //only to print duplicates
    int lastduplicate = 0;
    for (int i = 0; i < size; i++)
    {
        if(a[i] == a[i+1] && lastduplicate != a[i]) {
            lastduplicate = a[i];
            cout << a[i] << endl;
        }
    }
    //to print dupicates with its cout
    for (int i = 0; i < size; i++)
    {
        if(a[i] == a[i+1]) {
            cout << a[i] << endl;
            int j = i;
            while (a[j] == a[i])
            {
                j++;
            }
            cout << a[i] << " in " << j-i << "times" << endl;
            i=j;  // inside for loop i modification is allowed; 
        }
    }
    
    
    



    

    
    //HASHING MEHTHOD
    // int h = *max_element(a,a+size);             
    // int l = *min_element(a,a+size);  

    // int H[h + 1] = {0};
    // for (int i = 0; i < size; i++) {
    //     H[a[i]]++;
    // }
    // for (int i = l; i < h ; i++)
    // {
    //     if(H[i] == 2) cout << i << endl;
    // }
    
    return 1;
}