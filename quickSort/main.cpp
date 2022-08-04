#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int left, int right)
{
    //写法一
    int pivot = v[left];
    int i = right + 1;
    for(int j = right; j > left; j--)
    {
        if(v[j] >= pivot)
        {
            i--;
            swap(v[i], v[j]);
        }
    }
    swap(v[i-1], v[left]);
    return (i-1);

    //写法二
    /*
    int pivot = v[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[right]);
    return i + 1;
     */
}

void quickSort(vector<int> &v, int left, int right)
{
    if(left >= right)
        return;

    int mid = partition(v, left, right);
    quickSort(v, left, mid-1);
    quickSort(v, mid+1, right);
}

void qsort(vector<int> &v)
{
    quickSort(v, 0, v.size()-1);
}

int main()
{
    vector<int> v{5, 3, 6, 8, 4, 1, 2};
    qsort(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    return 0;
}