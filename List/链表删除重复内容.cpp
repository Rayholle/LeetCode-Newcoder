//
//  unique_erase_list.cpp
//  C++_test
//
//  Created by 金瑞志 on 2018/10/2.
//  Copyright © 2018年 金瑞志. All rights reserved.
//

#include <stdio.h>
#include <iostream>

typedef struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
}ListNode;

ListNode* deleteDuplication(ListNode* pHead)
{
    if(!pHead || !pHead->next)
        return NULL;
    ListNode* pre = pHead;
    ListNode* cur = pre->next;
    ListNode* last = cur->next;
    while(cur->next){
        if(cur->val!=last->val){
            pre=pre->next;
            cur=cur->next;
            last=cur->next;
        }
        else{
            while(last&&last->val == cur->val){
                last= last->next;
            }
            if(last!=NULL){
                cur = last;
                pre->next=cur;
                last=cur->next;
            }
            else{
                cur = last;
                pre->next = cur;
                break;
            }
        }
    }
    ListNode* temp = pHead->next;
    while(1)
    {
        if(pHead->val != temp->val)//一和二比，因为23一定不同
            break;
        else
        {
            pHead = temp->next;
            break;
        }
    }
    return pHead;
}
void print_list(ListNode* head)
{
    if(head==NULL){
        std::cout << "NULL";
        return;
    }
    while(head)
    {
        std::cout << head->val << "\t" ;
        head = head->next;
    }
}
int main_listnode1()
{
    ListNode* head = new ListNode(1);
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(3);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(4);
    ListNode* six = new ListNode(4);
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    print_list(head);
    std::cout << std::endl;
    ListNode* ret = new ListNode(0);
    ret = deleteDuplication(head);
    print_list(ret);
    std::cout << std::endl;
    
    return 0;
}


