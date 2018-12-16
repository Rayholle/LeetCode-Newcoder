#include <iostream>
#include <queue>
#include <vector>
vector<int> printFromToptoBottom(TreeNode* root){
    vector<int> res;
    if(!root)
        return res;
    queue<TreeNode*> treeQueue;//定义存储树结点指针的队列
    treeQueue.push(root);
    while(!treeQueue.empty())//队列非空进行循环
    {
        TreeNode* temp = treeQueue.front();
        treeQueue.pop();
        if(temp == nullptr) continue;
        treeQueue.push(temp->left);//不论temp有无左右子树均入队,且从左至右先入左孩子再入右孩子
        treeQueue.push(temp-right);
        res.push_back(temp->val);//传值入输出vector中
    }
    return res;
}
