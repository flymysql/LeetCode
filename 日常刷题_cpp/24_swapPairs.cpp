/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode* swap_node(ListNode &p){
        ListNode* s1 = p.next, *s2 = s1->next, *tmp = s2->next;
        s2->next = s1;
        s1->next = tmp;
        p.next = s2;
        return s1;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *h = head->next, *tmp = head, *first = h->next;
        h->next = tmp;
        tmp->next = first;
        while(tmp != NULL && tmp->next != NULL && tmp->next->next != NULL){
            tmp = swap_node(*tmp);
        }
        return h;
    }
};

/*
执行用时 : 8 ms, 在Swap Nodes in Pairs的C++提交中击败了96.14% 的用户
内存消耗 : 8.6 MB, 在Swap Nodes in Pairs的C++提交中击败了80.30% 的用户
*/
