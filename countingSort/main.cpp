// Created by ustc.jiangtao on 2023/6/15.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& a)
{
    int len = a.size();
    if (len == 0)
        return;
    int MIN = *(min_element(a.begin(), a.end()));
    int MAX = *(max_element(a.begin(), a.end()));

    vector<int> bucket(MAX - MIN + 1, 0);  //用来统计每个数出现的频率
    for (int i = 0; i < len; i++)
    {
        bucket[a[i] - MIN]++;  //注意偏移量
    }

    int index = 0, i = 0;
    while (index < len)
    {
        if (bucket[i])
        {
            a[index] = i + MIN;
            bucket[i]--;
            index++;
        }
        else
            i++;
    }
}

int main()
{
    vector<int> v{5, 3, 6, 8, 4, 1, 2, 5, 8, 3, 3};
    countingSort(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    return 0;
}