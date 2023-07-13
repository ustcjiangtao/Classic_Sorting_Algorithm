// Created by ustc.jiangtao on 2023/6/15.
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int>& v1, vector<int>& v2)
{
    int len1 = v1.size();
    int len2 = v2.size();
    vector<int> res(len1+len2);
    int i = 0, j = 0, k = 0;
    while(i < len1 && j < len2)
    {
        if(v1[i] <= v2[j])
        {
            res[k++] = v1[i++];
        }else{
            res[k++] = v2[j++];
        }
    }
    while(i < len1)
    {
        res[k++] = v1[i++];
    }
    while(j < len2)
    {
        res[k++] = v2[j++];
    }
    return res;
}

int main()
{
    vector<int> v1{3, 5, 6, 8};
    vector<int> v2{1, 2, 4};
    vector<int> res = mergeSort(v1, v2);
    for(auto it = res.begin(); it != res.end(); it++)
        cout << *it << " ";
    return 0;

}
