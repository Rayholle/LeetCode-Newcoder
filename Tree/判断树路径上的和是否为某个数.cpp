#include <iostream>
#include "vector"

class TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right
public:
    TreeNode(int _val=0):val(_val),left(nullptr),right(nullptr){}
};
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
{
    vector<int> trace;
    vector<vector<int>> ret;
    if(root)
        dfs(root, expectNumber, trace, ret);
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
        dfs(root->left, S-root->val, trace, ret);
    if(root->right)
        dfs(root->right, S-root->val, trace, ret);
    trace.pop_back();
}
