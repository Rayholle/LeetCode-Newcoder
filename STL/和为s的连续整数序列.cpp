#include<iostream>
#include"vector"

vector<vector<int> > FindContinuousSequence(int sum) {
        int plow = 1;
        int phigh = 2;
        vector<vector<int>> ret;
        while(plow < phigh){
            int cur = (plow+phigh)*(phigh-plow+1)/2;//求和公式计算当前和
            if(cur < sum)//若小于sum，则phigh++
                phigh++;
            if(cur == sum){
                vector<int> temp;
                for(int i = plow; i<= phigh; i++){
                    temp.push_back(i);
                }
                ret.push_back(temp);
                plow++;
            }
            if(cur > sum)//若大于sum，则plow++
                plow++;
        }
        return ret;
    }
