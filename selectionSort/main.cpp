#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &a)
{
    int len = a.size();
    for (int i = 0, minIndex; i < len - 1; i++) //需要循环次数
    {
        minIndex = i;                     //最小元素的下标!!
        for (int j = i + 1; j < len; j++) //访问未排序的元素
        {
            if (a[j] < a[minIndex])
                minIndex = j; //找到最小的元素下标
        }
        swap(a[i], a[minIndex]);
    }
}

int main()
{
    vector<int> v{5, 3, 6, 8, 4, 1, 2};
    selectionSort(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    return 0;
}
