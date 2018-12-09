//
//  树的遍历.cpp
//  数据结构_demo
//
//  Created by 金瑞志 on 2018/8/29.
//  Copyright © 2018年 金瑞志. All rights reserved.
//
//树的二叉链表表示法
typedef struct BiTNode{
    int         data;
    BiTNode     *L_child,*R_child;
}BiTNode, *BiTree;
#include <stdio.h>
#include <iostream>
#include "stack"
using namespace std;
//先序遍历
void preorder(BiTNode* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<< root->data << "\t";
    preorder(root->L_child);
    preorder(root->R_child);
    
}
//中序遍历
void midorder(BiTNode* root)
{
    if(root == NULL)
    {
        return;
    }
    midorder(root->L_child);
    cout<< root->data << "\t";
    midorder(root->R_child);
    
}
//后序遍历
void lastorder(BiTNode* root)
{
    if(root == NULL)
    {
        return;
    }
    lastorder(root->L_child);
    lastorder(root->R_child);
    cout<< root->data << "\t";
}
//叶子节点个数的计算
void numofTree(BiTNode* root,int &num)
{
    if(root->L_child==NULL && root->R_child==NULL)
    {
        num++;
        return;
    }
    if(root!=NULL)
    {
        if(root->L_child!=NULL)
        {
            numofTree(root->L_child,num);
        }
        if(root->R_child!=NULL)
        {
            numofTree(root->R_child,num);
        }
    }
}
//求树的深度
int lengthofTree(BiTNode* root)
{
    int length = 0;
    int L_length = 0;
    int R_length = 0;
    if(root == NULL)
    {
        length = 0;
        return length;
    }
    L_length = lengthofTree(root->L_child);
    R_length = lengthofTree(root->R_child);
    length = 1+(L_length>R_length?  L_length:R_length);
    return length;
}
BiTNode* copyTree(BiTNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    BiTNode* NewNode = NULL;
    BiTNode* Left = NULL;
    BiTNode* Right = NULL;
    
    Left = copyTree(root->L_child);
    Right = copyTree(root->R_child);
    
    NewNode = (BiTNode*)malloc(sizeof(BiTNode));
    if(NewNode == NULL)
        return NULL;
    NewNode->L_child = Left;
    NewNode->R_child = Right;
    NewNode->data = root->data;
    
    return NewNode;
}
//非递归遍历方法，借助栈进行中序遍历
//找子树的最左节点
BiTNode* goLeft(BiTNode* root,stack<BiTNode*> &s)
{
    if(root == NULL)
        return NULL;
    while(root->L_child != NULL)
    {
        s.push(root);
        root = root->L_child;
    }
    return root;
    //这个root就是最左节点
}
void Non_midorder(BiTNode* root)
{
    if(root == NULL)
        return;
    BiTNode* left = NULL;
    stack<BiTNode*> s;
    left = goLeft(root, s);
    while(left)
    {
        //输出最左节点数据
        cout << left->data << "\t";
        //如果存在右子树，重复步骤一，寻找其最左节点
        if(left->R_child)
            left = goLeft(left->R_child, s);
        //如果右子树为空，根据栈顶元素返回
        else if(!s.empty())
        {
            left = s.top();
            s.pop();
        }
        else
            left = NULL;
    }
}
int main()
{
    //先定义几个节点
    BiTNode A,B,C,D,E,F,G,H,I;
    A.data = 1;B.data = 2;C.data = 3;D.data = 4;E.data = 5;F.data = 6;G.data = 7;H.data=8;I.data=9;
    //自定义树的结构
    A.L_child =&B;B.L_child=NULL;B.R_child=&C;C.L_child=&D;C.R_child=&E;D.L_child=D.R_child=NULL;E.L_child=E.R_child=NULL;
    A.R_child=&F;F.L_child=&G;F.R_child=&H;G.L_child=G.R_child=NULL;H.L_child=&I;H.R_child=NULL;
    I.L_child=I.R_child=NULL;
    int numoftree = 0;
    int depth = 0;
    //先序遍历
    cout<<"\n先序遍历：\n";
    preorder(&A);
    //中序遍历
    cout<<"\n中序遍历：\n";
    midorder(&A);
    //后序遍历
    cout<<"\n后序遍历：\n";
    lastorder(&A);
    //求树叶子节点的个数
    numofTree(&A,numoftree);
    cout<<"\n该树的叶子节点数为："<<numoftree;
    //求树的深度
    depth = lengthofTree(&A);
    cout<<"\n该树的深度为："<<depth;
    //copy一个树
    BiTNode* a = copyTree(&A);
    cout<<"\n原来的树（先序遍历）：\n";
    preorder(&A);
    cout<<"\n新的树（先序遍历）：\n";
    preorder(a);
    //非递归中序遍历a
    cout<< "\n非递归中序遍历：\n";
    Non_midorder(a);
    cout<<"\nWellDone!\n";
    return 0;
}
