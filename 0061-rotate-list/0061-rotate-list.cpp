/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int lengthLL(ListNode *head) {
        if (!head) return 0;
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        ListNode *dummyHead = head;
        int len = lengthLL(head);
        k = k % len;
        if (k == 0) return head;
        k = len - k;
        auto temp = head;
        for (int i = 1; i < k;i++) {
            temp = temp->next;
        }
        auto next = temp->next;
        auto returnedHead = next;        
        if (temp)
            temp->next = NULL;
        while (next && next->next) {
            next = next->next;
        }
        next->next = dummyHead;
        return returnedHead;
    }
};