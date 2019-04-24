// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
// 示例:

// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 暴力法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool flag = true;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                flag = false;
            }
            else{
                lists.erase(lists.begin() + i);
                i --;
            }
        }
        if(flag) return NULL;
        else if(lists.size() == 1) return lists[0];
        int tmp = lists[0]->val;
        ListNode head = ListNode(tmp);
        ListNode *tmd = &head;
        head.next = tmd;
        int it = 0;
        while(lists.size() > 0){
            for(int i=0; i<lists.size(); i++){
                if(lists[i]->val <= tmp){
                    it = i;
                    tmp = (*lists[i]).val;
                }
            }
            if(lists[it] != NULL){
                (*tmd).next = lists[it];
                tmd = lists[it];
                if((*lists[it]).next == NULL){
                    lists.erase(lists.begin() + it);
                }
                else
                    lists[it] = (*lists[it]).next;
                it = 0;
                tmp = (*lists[0]).val;
                }
            else break;
            }
        return head.next;
    }
};

/* 暴力法
执行用时 : 280 ms, 在Merge k Sorted Lists的C++提交中击败了20.69% 的用户
内存消耗 : 10.8 MB, 在Merge k Sorted Lists的C++提交中击败了95.40% 的用户
*/


// 最小堆法
struct cmp {
	bool operator()(ListNode *a, ListNode *b){
		return a->val > b->val;
	}
};
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<ListNode*>, cmp> heap;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL) heap.push(lists[i]);
        }
        if(heap.empty()) return NULL;
        ListNode *q = heap.top();
        ListNode *head = q, *p = NULL;
        while(!heap.empty()){
            q = heap.top();
            heap.pop();
            if(q->next != NULL) heap.push(q->next);
            if(p == NULL){
                p = q;
                continue;
            }
            p->next = q;
            p = p->next;
        }
        return head;
    }
};

/*
执行用时 : 56 ms, 在Merge k Sorted Lists的C++提交中击败了68.65% 的用户
内存消耗 : 10.9 MB, 在Merge k Sorted Lists的C++提交中击败了93.96% 的用户
*/