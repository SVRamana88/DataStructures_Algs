  /* int bins(int start,int end,int ele)
{
    
    int size = end - start,mid;

    // if (size % 2 == 0) mid = (start + end) / 2;
    // else mid = (start + end) / 2 + 1; 
    mid = start + (end - start) / 2;

    if (end != 1 && start != 10) {
    if (ele == a[mid]) return mid-1;
    else if(ele < a[mid-1]) {
        end = mid-1;
        return bins(start,end,ele);
    }
    else {
        start = mid+1;
        return bins(start,end,ele);  
    }
    }
    else return -1;
}
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int binsearch(int a[], int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    system("cls");
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binsearch(a, 0, 9, 99) << endl;
    return 0;
}
