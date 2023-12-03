/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int lengthLL(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = lengthLL(headA);
        int cnt2 = lengthLL(headB);
        int diff = abs(cnt1 - cnt2);
        while (cnt1 > cnt2) {
            headA = headA->next;
            cnt1--;
        }
        while (cnt2 > cnt1) {
            headB = headB->next;
            cnt2--;
        }
        while (headA != headB && headA && headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};