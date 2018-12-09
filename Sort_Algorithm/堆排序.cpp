//
//  堆排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/10.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*堆排序：
 利用大顶堆与小顶堆的性质
 大小顶堆的原型-》为完全二叉树，所以n个结点时有孩子的结点为1--n/2（下标）其孩子结点的下标为2*m和2*m+1
 现将数组构造成大顶堆
 然后取出顶堆头部元素（最大元素），并用顶堆尾部元素取而代之
 循环遍历，一次取出剩余顶堆结构中最大的头部元素，即可排序成功
 堆排序为了创造满足完全二叉树性质的数组，数组0下标元素不参与排序
 */
 
 
#include <stdio.h>
#include <iostream>
#include "vector"
using namespace std;
void swap(int& n1, int& n2);
void heapAdjust(vector<int> &Array, int s, int m)
{
    /*传入下标为s的元素，遍历他的孩子结点和子树（如果有的话）找到最大值，赋给这个s下标根节点位置
     使该位置元素为该子树中最大值*/
    int j;
    int temp = Array[s];
    for(j = 2*s; j <= m; j=j*2){
        if(j<m && Array[j] < Array[j+1])
            j++;
        if(temp >= Array[j])//最先传入的s为最靠近叶子结点的双亲结点，后续进来的s其子树一定是拍好序的顶堆结构
           break;
        Array[s] = Array[j];
        s = j;
    }
    Array[s] = temp;
}

void heapSort(vector<int> &Array)
{
    int i;
    unsigned long length = Array.size();
    /*完整数组进行顶堆结构*/
    for(i = (int)length/2; i > 0; i--){
        heapAdjust(Array, i, (int)length);
    }
    /*循环遍历取出最大值*/
    for(i = (int)length-1; i > 1; i--){
        swap(Array[1], Array[i]);
        heapAdjust(Array, 1, i-1);
    }
}
