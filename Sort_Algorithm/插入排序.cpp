//
//  插入排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/10.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*插入排序
 原理很简单，类似于我们打扑克牌
 每次新摸到的牌插入到原有序的牌中
 插入过程为：该牌与原有序序列末尾比较，弱小则末尾数后移直到遇到比该数小的元素
 */
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
void swap(int &a, int &b);//插入排序不需要用到交换，其实也需要用到，但只是元素后移
void insertSort(vector<int>& Array)
{
    int i, j, temp;
    unsigned long length = Array.size();
    for(i=1; i<length; i++){
        temp = Array[i];
        for(j=i-1; temp<Array[j]; j--){
            //元素后移
            Array[j+1] = Array[j];
        }
        Array[j+1] = temp;
    }
}
