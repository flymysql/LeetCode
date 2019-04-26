/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

// Definition for singly-linked list.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        vector<ListNode*> arr;
        while(head != NULL){
            arr.push_back(head);
            head = head->next;
        }
        if(arr.size() < k)
            return arr.front();
        for(int i = 0; i <= arr.size()-k; i += k)
            for(int j = 0; j < k/2; j++)
                swap(arr[i+j], arr[i+k-j-1]);
        for(size_t i = 0; i < arr.size()-1; i++){
            arr[i]->next = arr[i+1];
        }
        arr.back()->next = NULL;
        return arr.front();
    }
}

/*
执行用时 : 32 ms, 在Reverse Nodes in k-Group的C++提交中击败了96.23% 的用户
内存消耗 : 10.1 MB, 在Reverse Nodes in k-Group的C++提交中击败了53.04% 的用户
*/