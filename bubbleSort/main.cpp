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

void bubbleSort2(vector<int> &a)  //写法二
{
    int len = a.size();
    for (int i = 0; i < len - 1; i++) //需要循环次数
    {
        for (int j = 0; j < len - 1 - i; j++) //每次需要比较次数
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]); //不满足偏序，交换
            }
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
