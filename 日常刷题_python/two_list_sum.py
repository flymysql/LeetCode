# Definition for singly-linked list.
# 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

# 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

# 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        tmp = 0
        s1 = l1
        s2 = l2
        s3 = ListNode(0)
        ss = s3
        while s1 != None and s2 != None:
            n = int((s1.val + s2.val + tmp) % 10)
            tmp = int((s1.val + s2.val + tmp - n) / 10)
            node = ListNode(n)
            ss.next = node
            ss = node
            s1 = s1.next
            s2 = s2.next
        s = None
        if s1 !=None:
            s = s1
        if s2 != None:
            s = s2
        while s != None:
            n = int((s.val + tmp) % 10)
            tmp = int((s.val + tmp - n) / 10)
            node = ListNode(n)
            ss.next = node
            ss = node
            s = s.next
        if tmp >= 1:
            node = ListNode(tmp)
            ss.next = node
            ss = node
        return s3.next
s = Solution()
l1 = ListNode(5)
l2 = ListNode(4)
l3 = ListNode(3)

k1 = ListNode(5)
k2 = ListNode(6)
k3 = ListNode(4)
# k1.next = k2
# k2.next = k3

# l1.next = l2
# l2.next = l3
ll = s.addTwoNumbers(l1,k1)

while ll != None:
    print(ll.val)
    ll = ll.next