//
//  希尔排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/10.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*希尔排序：作为第一批突破O(n^2)达到O(nlogn)的排序算法
 其主要依赖于插入算法的改进
 插入算法比较相邻key，进行后移，然后插入
 希尔排序设置增量，对每个增量间隔key进行分组，然后插入排序（类似报数，喊1的为一组喊2的为一组。。。）
 不断改变增量直到增量为1，然后在进行相邻项的比较，弱大小反向则交换
 */
#include <stdio.h>
#include <iostream>
#include "vector"
using namespace std;

void shellSort(vector<int> &Array)
{
    int i,j;
    unsigned long length = Array.size();
    int increment = (int)length;
    int temp = -1;
    
    do
    {
        increment = increment/3 + 1;
        for(i = increment; i < length; i++){
            if(Array[i] < Array[i-increment])//类似插入排序，当前数比前位数小需要插入
            {
                temp = Array[i];
                for(j = i-increment; j>0 && (Array[j] > temp); j=j-increment){
                    Array[j+increment] = Array[j];
                }
                Array[j+increment] = temp;
            }
        }
    }while(increment > 1);
}

