#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &a)
{
    int len = a.size();
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < gap; i++)
        {
            for (int j = i + gap, temp, preIndex; j < len; j = j + gap) //依旧需要temp作为哨兵
            {
                temp = a[j];        //保存哨兵
                preIndex = j - gap; //将要对比的编号
                while (preIndex >= 0 && a[preIndex]>temp)
                {
                    a[preIndex + gap] = a[preIndex]; //被替换
                    preIndex -= gap;                 //向下走一步
                }
                a[preIndex + gap] = temp; //恢复被替换的值
            }
        }
    }
}


int main()
{
    vector<int> v{5, 3, 6, 8, 4, 1, 2};
    shellSort(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    return 0;
}