//
//  简单排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/8.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*简单排序：
 主要思想是向后遍历数组，将当前值最为最小值，如果有比该值小的数，更改min的值为最小值的下标
 O(n^2)时间复杂度，但是交换次数固定为n-1，这是在冒泡排序不停比较和交换基础上的改进
 */
#include <stdio.h>
#include "vector"
using std::vector;

extern void swap(int &a, int &b);
void simpleSort(vector<int>& Array)
{
    short int i,j,min;
    unsigned long length = Array.size();
    for(i = 0; i < length; i++){
        min = i;//将当前下标记录为最小值下标
        for(j = i; j < length; j++){
            if(Array[j]<Array[min])
                min = j;
        }
        if(min != i)//如果最小值下标改变
            swap(Array[i], Array[min]);
    }
}

