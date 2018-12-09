//
//  冒泡排序.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/11/8.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
/*排序算法-冒泡排序
 临近关键字比较，两次循环遍历
 依次将最小值从数据池中冒出（排到队首）
 */
/* 该算法是最差的算法，因为比较和交换次数最多*/
#include <iostream>
#include <ctime>
#include "vector"
using namespace std;

static vector<int> test_Array;
void swap(int &a, int &b);
void simpleSort(vector<int>& Array);
void insertSort(vector<int>& Array);
void shellSort(vector<int> &Array);
void heapSort(vector<int> &Array);
void MergeSort(vector<int> &Array);
void MergeSort_inrecursion(vector<int>& Array);
void QuickSort(vector<int>& Array);

void maopao_Sort(vector<int>& Array)
{
    short int length = Array.size();
    for(int i = 0; i < length; i++){
        for(int j = length-1; j>i; j--){
            if(Array[j] < Array[j-1])
                swap(Array[j], Array[j-1]);
        }
    }
}
/*一个改进的冒泡排序*/
void maopao_sort_new(vector<int>& Array)
{
    bool flag = true;
    short int length = Array.size();
    for(int i = 0; i < length && flag; i++){
        flag = false;
        for(int j = length-1; j>i; j--){
            if(Array[j]<Array[j-1]){
                swap(Array[j], Array[j-1]);
                flag = true;
            }
        }
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
template<typename T>
void print_Vector(vector<T>& V)
{
    unsigned long length = V.size();
    for(int i = 0; i < length; i++)
    {
        cout<<V[i]<<"\t";
    }
    cout<<"数据输出结束" << endl;
}
int main_sort()
{
    //冒泡排序算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    clock_t start = clock();
    maopao_Sort(test_Array);
    clock_t end = clock();
    print_Vector(test_Array);
    double c_time = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"冒泡程序执行时间： "<< c_time << endl;
    
    //添加flag后的优化算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    maopao_sort_new(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time2 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"改进的冒泡程序执行时间： "<< c_time2 << endl;
    
    
    //简单排序算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    simpleSort(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time3 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"简单排序算法程序执行时间： "<< c_time3 << endl;
    
    //插入排序算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    insertSort(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time4 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"插入排序算法程序执行时间： "<< c_time4 << endl;
    
    //希尔排序算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    shellSort(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time5 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"希尔排序算法程序执行时间： "<< c_time5 << endl;
    
    //堆排序算法
   test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    heapSort(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time6 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"堆排序算法程序执行时间： "<< c_time6 << endl;
    
    //归并排序
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    MergeSort(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time7 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"归并排序算法(递归）程序执行时间： "<< c_time7 << endl;
    
    //归并排序非递归算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    MergeSort_inrecursion(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time8 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"归并排序算法(非递归）程序执行时间： "<< c_time8 << endl;
    
    //快速排序算法
    test_Array = {0,13,3,14,7,8,7,6,8,2,9,5,13,7,15,19,11,12,14,9};
    start = clock();
    QuickSort(test_Array);
    end = clock();
    print_Vector(test_Array);
    double c_time9 = (double)(end - start)/CLOCKS_PER_SEC;
    cout<<"快速排序算法程序执行时间： "<< c_time9 << endl;

    return 0;
}
