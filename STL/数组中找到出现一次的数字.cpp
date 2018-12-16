#include<iostream>
#include<vector>

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int temp =0;
        int index = 1;
        int num_one= 0;
        int num_two= 0;
        //第一次遍历对所有值进行异或
        for(int i = 0; i < data.size(); i++)
        {
            temp^=data[i];
        }
        //找出二进制temp中第个1的位置
        for(index; index<INT_MAX; index=index<<1)
        {
            if(temp&(index))
                break;
        }
        for(int i =0; i< data.size(); i++)
        {
            if(data[i]&(index))
                num_one^=data[i];
            else
                num_two^=data[i];
        }
        *num1 = num_one;
        *num2 = num_two;
    }
