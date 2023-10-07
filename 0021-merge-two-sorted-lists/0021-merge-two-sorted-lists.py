# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, h1: Optional[ListNode], h2: Optional[ListNode]) -> Optional[ListNode]:
        if not h1:
            return h2
        if not h2:
            return h1
        if h1.val > h2.val:
            h2.next = self.mergeTwoLists(h1,h2.next)
            return h2
        else:
            h1.next = self.mergeTwoLists(h1.next, h2)
            return h1