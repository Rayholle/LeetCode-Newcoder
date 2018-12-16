#include<iostream>
#include<vector>

void nextPermutation(vector<int>& nums){
    int length = nums.size();
    if(length == 0 || length == 1)
        return;
    int j = length -1;
    for(; j>0; j--){
        if(nums[j] > nums[j-1]){//若找到可交换点，寻找后续的另一个交换点
            int min = j;
            for(int k = j+1; k < length; k++){
                if(nums[min]>nums[k] && nums[j-1]<nums[k]) min = k;//j后续下标中最小且大于j-1的下标
        }
            //交换min与j-1的value
            int temp = nums[j-1];
            nums[j-1] = nums[min];
            nums[min] = temp;
            break;//交换完 跳出循环
        }
    }
    //从j位置开始插入排序
    for(int i = j+1; i <length; i++){
        int temp = nums[i];
        int k = i-1;
        for(; k >=j&&nums[k]>temp; k--) nums[k+1] = nums[k];
        nums[k+1] = temp;
    }
}
