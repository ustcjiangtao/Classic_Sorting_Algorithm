#include <iostream>
#include <vector>
using namespace std;

void bubbleSort1(vector<int> &v)  //写法一
{
    bool swapp = true;
    while(swapp)
    {
        swapp = false;
        for(int i = 0; i < v.size()-1; i++)
        {
            if(v[i] > v[i+1])
            {
                swap(v[i], v[i+1]);
                swapp = true;
            }
        }
    }
}

void bubbleSort2(vector<int> &a)  //写法二(易懂)
{
    int len = a.size();
    for (int i = 0; i < len - 1; i++) //需要循环次数（n个元素需要扫描n-1轮）
    {
        bool flag = false;  //flag用来判断是否执行了数据交换的操作（当在一轮扫描完成后，检查在这一轮中是否执行了数据交换操作，若没有，则表示整个数列已经排序完成，可以直接跳出循环）
        for (int j = 0; j < len - 1 - i; j++) //每次需要比较次数（每轮需要比较的次数逐步减少）
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]); //不满足偏序，交换
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

int main() {
    vector<int> v{5, 3, 6, 8, 4, 1, 2};
    //bubbleSort1(v);
    bubbleSort2(v);
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    return 0;
}
