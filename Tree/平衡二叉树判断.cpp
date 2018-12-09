'''
2018.12.7
RuiZhi
'''
class TreeNode{
public:
    TreeNode(int _val) : val(_val),left(nullptr),right(nullptr){}
public:
    TreeNode* left,right;
    int val;
}; 
#include <iostream>

int main(){
    return (getLength(pRoot)!=-1)?false:getLength(pRoot);
}
//这里没有创建树的部分，空了会加生成树的代码
int getLength(TreeNode* pRoot){
    if(pRoot == nullptr)
        return 0;
    int leftLength = getLength(pRoot->left);
    if(leftLength == -1)
        return -1;
    int rightLength = getLength(pRoot->right);
    if(rightLength == -1)
        return -1;
    return abs(leftLength,rightLength)>1?-1:1+max(leftLength,rightLength);
}
