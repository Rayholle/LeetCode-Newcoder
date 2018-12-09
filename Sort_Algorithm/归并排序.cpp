//
//  归并排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/11.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*归并排序算法：稳定的O(nlogn)算法
 包括两种实现思路：递归与非递归
 递归思路：
    将数组不断拆分，直到每个元素独立（递归）；
    递归栈弹出，对当前拆分后的元素两两合并（关键的Merge函数）
 非递归思路：
    将每个元素看成独立，而不需要递归拆分；
    每次1->2->4->8进行合并
 */
#include <stdio.h>
#include "vector"
#include <iostream>
using namespace std;
/*递归型*/
void Merge(vector<int>& Array, int i, int m, int tail, vector<int>& result)
{
    int j, flag, l;
    int a = i;
    //k为前数组下标， j为后数组下标，比较两者小者归并入数组result[ini]
    for(j=m+1, flag=i; j <= tail && i <= m; flag++){
        if(Array[i] <= Array[j])
            result[flag] = Array[i++];
        else
            result[flag] = Array[j++];
        //cout << result[flag];
    }
    if(j <= tail){
        for(l = 0; l <= tail-j; l++)
            result[flag+l] = Array[j+l];
    }
    if(i <= m){
        for(l = 0; l <= m-i; l++)
            result[flag+l] = Array[i+l];
    }
    for(int x = a; x <= tail; x++){
        Array[x] = result[x];
        // std::cout << result[i] <<"\t";
    }
    //cout << endl;
}
void merge(vector<int>& data,int start,int end,vector<int>& result)
{
    int left_length = (end - start + 1) / 2 + 1;//左部分区间的数据元素的个数
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //对分别已经排好序的左区间和右区间进行合并
        if(data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }
    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];
    while(right_index < end+1)
        result[result_index++] = data[right_index++];
}
void MSort(vector<int>& Array, int start, int end, vector<int>& result)
{
    int m;
    if(start == end)
        return;
    else{
        m = (end+start)/2;
        MSort(Array, start, m, result);
        MSort(Array, m+1, end, result);
        Merge(Array, start,m, end, result);
//  移动到了Merge函数中      
//        for(int i = start; i <= end; i++){
//            Array[i] = result[i];
//           // std::cout << result[i] <<"\t";
//        }
//        //cout << endl;
    }
}
void MergeSort(vector<int>& Array)
{
    unsigned long length = Array.size();
    vector<int> result(length);
    MSort(Array, 1, (int)length-1, result);
}
/*可以可以 弄了一天终于调试好了
 问题就出在首先没有在每次调用Merger函数后为归并好的部分（start-end）赋给源数组
 其次更重要的问题出在Merger函数中flag与i颠倒导致组内排序错误
 */
/*非递归型*/
void MergePass(vector<int>& Array, vector<int>& result, int k, int tail)
{
    //这里需要调用之前写好的Merge函数
    //并且更重要的是这里的数值经过精确推算
    //k为归并单位元素个数，例如k=2即为2个元素与2个元素合并为4个元素
    //所以i=i+2*k
    //i+2*k不能超过尾部下标tail
    int i = 1;
    for(i = 1; i <= tail-2*k; i+=2*k){
        Merge(Array, i, i+k-1, i+2*k-1, result);
    }
    //如果i，m在tail以内的话，在merge余下的数组
    if(i < tail-k+1){
        Merge(Array, i, i+k-1, tail, result);
    }
    else{
        for(int j = i; j <= tail; j++)
            result[j] = Array[j];
    }
        
}
void MergeSort_inrecursion(vector<int>& Array)
{
    unsigned long length = Array.size();
    vector<int> result(length);
    int k =  1;
    
    while(k < length){
        MergePass(Array, result, k, (int)length-1);
        k*=2;
    }
}
