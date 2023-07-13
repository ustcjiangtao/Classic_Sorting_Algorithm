// Created by ustc.jiangtao on 2023/6/15.

#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(vector<int>& v, int start, int end)  //将区间【start， end】调整为大根堆
{
    int dad = start;
    int son = 2 * dad + 1;  //左孩子（右孩子为2 * dad + 2）
    while (son <= end)
    {
        if (son + 1 <= end && v[son] < v[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (v[dad] > v[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(v[dad], v[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heapSort(vector<int>& v)
{
    int len = v.size();
    for(int i = len/2 - 1; i >= 0; i--)  //构造初始大根堆
    {
        max_heapify(v, i, len-1);
    }

    for (int i = len - 1; i > 0; i--)   //堆排序过程
    {
        swap(v[0], v[i]);
        max_heapify(v, 0, i - 1);
    }
}

int main()
{
    vector<int> v{5, 3, 6, 8, 4, 1, 2};
    heapSort(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    return 0;
}

