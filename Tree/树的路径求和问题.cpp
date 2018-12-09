//
//  树的路径求和问题.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/9/2.
//  Copyright © 2018年 金瑞志. All rights reserved.
//

//#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

 typedef struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
 TreeNode(int x) :
 val(x), left(NULL), right(NULL) {
 }
 }TreeNode;

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> trace;
        vector<vector<int>> ret;
        if(root)
            dfs(root, expectNumber, trace, ret);
        
        print_vector(ret);
        return ret;
    }
    void dfs(TreeNode* root,int S, vector<int>& trace, vector<vector<int>>& ret){
        trace.push_back(root->val);
        //判断是否为叶子节点
        if(!root->left && !root->right){
            if(S == root->val)
                ret.push_back(trace);
        }
        if(root->left)
            dfs(root->left , S-root->val, trace, ret);
        if(root->right)
            dfs(root->right, S-root->val, trace, ret);
        trace.pop_back();
    }
    void print_vector(vector<vector<int>>& v)
    {
        for(vector<vector<int>>::iterator it1 = v.begin(); it1!=v.end(); it1++){
            vector<int> temp = *it1;
            for(vector<int>::iterator it2 = temp.begin(); it2!=temp.end(); it2++){
                cout << *it2 << "\t";
            }
            cout << "\n";
        }
    }
};
//先序遍历
void preorder(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<< root->val << "\t";
    preorder(root->left);
    preorder(root->right);
}

int main_tree1()
{
    //先定义几个节点
    TreeNode A(4),B(2),C(3),D(3),E(5),F(3),G(7),H(2),I(3);
    //A.data = 1;B.data = 2;C.data = 3;D.data = 4;E.data = 5;F.data = 6;G.data = 7;H.data=8;I.data=9;
    //自定义树的结构
    A.left =&B;B.left=NULL;B.right=&C;C.left=&D;C.right=&E;D.left=D.right=NULL;
    E.left=E.right=NULL;
    A.right=&F;F.left=&G;F.right=&H;G.left=G.right=NULL;H.left=&I;H.right=NULL;
    I.left=I.right=NULL;
    Solution S1;
    //preorder(&A);
    S1.FindPath(&A, 12);
    
    vector<int> t1,t2;
    t1.push_back(1);
    t1.push_back(2);
    t1.push_back(3);
    t1.push_back(4);
    
    t2.push_back(5);
    t2.push_back(6);
    t2.push_back(7);
    t2.push_back(8);
    
    vector<vector<int>> T;
    T.push_back(t1);
    T.push_back(t2);
   // S1.print_vector(T);
    return 0;
}
