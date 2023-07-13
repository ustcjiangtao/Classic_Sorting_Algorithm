#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &v)
{
    int length = v.size();
    int i,j;
    for(i = 1; i < length; i++)
    {
        int tmp = v[i];
        for(j = i; j > 0 && v[j-1] > tmp; j--)
        {
            v[j] = v[j-1];
        }
        v[j] = tmp;
    }
}

int main() {
    /*
    vector<int> v{5,6,3,4,2,7};
    sort(v.begin(), v.end(), less());
    sort(v.begin(), v.end(), greater());
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it <<" ";
    return 0;
     */

    vector<int> v{5,6,3,4,2,7};
    insertionSort(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it <<" ";
    return 0;
}
