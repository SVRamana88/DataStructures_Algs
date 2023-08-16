#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{                             
    int l[12] = {5,6,8,9,10,13,14,15};
    int d = l[0]-0;
    for (int i = 1; i < 8; i++)
    {
        if(d != l[i]-i) {
            while (d<l[i]-i)
            {
                cout << i + d << endl;
                d++;
            }
        }
    }
    // int d;
    // for (int i = 0; i < 8; i++)
    // {
    //     if(l[i] != l[i+1] + 1) {
    //         d = l[i+1] - l[i];
    //         for (int j = 1; j < d; j++)
    //         {
    //             cout << l[i] + j;
    //         }  
    //     }
    // }
    



    return 1;
}
