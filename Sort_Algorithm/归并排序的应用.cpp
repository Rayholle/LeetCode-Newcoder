//
//  归并排序的应用.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/14.
//  Copyright © 2018年 金瑞志. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "vector"
using namespace std;

void Merge(vector<int>& A, vector<int>& B, vector<int>& result){
    int i = 0;
    int m = A.size() -1;
    int n = B.size() -1;
    int j,k,l;
    for(k=i, j=i; i<=m&&j<=n;){
        if(A[i] <= B[j])
            result[k++]=A[i++];
        else
            result[k++]=B[j++];
    }
    if(i<=m)
        for(int l=0; l<=m-i; l++)
            result[l+k]=A[i+l];
    if(j<=n)
        for(int l=0; l<=n-j; l++)
            result[l+k]=B[j+l];
//    for(int l = 0; l < result.size(); l++){
//        cout << result[l] << "\t";
//    }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*相当于两个有序子数组进行归并排序，再对排好序的数组寻找中位数*/
    int allLength = nums1.size() + nums2.size();//用于寻找合并后数组的中位数
    vector<int> result(allLength, 0);
    Merge(nums1, nums2, result);
        for(int l = 0; l < result.size(); l++){
            cout << result[l] << "\t";
        }
    cout << allLength << endl;
    float ret = (allLength%2==0)? (float)(result[allLength/2]+result[allLength/2-1])/2.0 : result[allLength/2];
    return ret;
}

int main_application()
{
    vector<int> a = {1,2,3};
    vector<int> b = {4,5,6};
    float ret = findMedianSortedArrays(a, b);
    cout << "中位数为：" << ret;
    return ret;
}
