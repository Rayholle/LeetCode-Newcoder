//
//  快速排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/12.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*快速排序算法一般使用递归实现
 传入数组、最低下标、最高下标
 重点在于对数组根据Array[low]进行二分，左边小于Array[pivot]，右边大于Array[pivot]
 再依次递归对数组进行low-pivot-1和pivot+1-high的拆分
 直至无法继续拆分（low==high）
 元素排序完毕*/
#include <stdio.h>
#include <iostream>
#include "vector"

using namespace std;
void swap(int& a, int& b);
int partition(vector<int>& Array, int low, int high)
{
    //选取pivot时的小优化，不是直接取low而是取左中右的中位数，使得pivot更加均匀的拆分数组
    int m = low + (high-low)/2;
    if(Array[low] > Array[high])/*使low处值小于high处*/
        swap(Array[low], Array[high]);
    if(Array[m] > Array[high])/*使m处值小于high处*/
        swap(Array[m], Array[high]);
    if(Array[m] > Array[low])/*使low处值为中位数*/
        swap(Array[m], Array[low]);
    int pivot_key = Array[low];
    while(low < high){
        while(low<high && pivot_key <= Array[high])
            high--;
        swap(Array[low], Array[high]);
        /*这里可以直接用high处值覆盖low处值，效率更高，只是最后需要将pivot_key值赋给Array[low]*/
        while(low<high && Array[low] <= pivot_key)
            low++;
        swap(Array[low], Array[high]);
        /*这里可以直接用low值覆盖high处值，效率更高*/
    }
    return low;
}
void Qsort(vector<int>& Array, int low, int high)
{
    int pivot;
    if(low < high){
        pivot = partition(Array, low, high);
        Qsort(Array, low, pivot-1);
        Qsort(Array, pivot+1, high);
    }
}
void QuickSort(vector<int>& Array)
{
    unsigned long length = Array.size();
    int low = 1;//0位置可以作为哨兵，这里从1开始
    Qsort(Array, low, (int)length-1);
}
