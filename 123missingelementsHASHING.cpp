#include<iostream>
#include<cstdlib>
#include <algorithm>
using namespace std;
int main()
{     
    system("cls");                        
    int a[] = {5,6,8,9,10,13,14,15};        //works for shorted and unshorted arrays
    int size = sizeof(a) / sizeof(a[0]);
    int h = *max_element(a,a+size);         //std::max_element(arr, arr + size);   (start,end);      
    int l = *min_element(a,a+size);


/*template <class ForwardIt>
ForwardIt max_element(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt largest = first;
    ++first;
    for (; first != last; ++first) {
        if (*largest < *first)
            largest = first;
    }
    return largest;
}*/                                              //predefined class max_element


     cout <<" min p : " << l << endl;
    int H[h + 1] = {0};
    for (int i = 0; i < 8; i++) {
        H[a[i]]++;
    }
    for (int i = l; i < h ; i++)
    {
        if(H[i] == 0) cout << i;
    }
    

    return 1;
}