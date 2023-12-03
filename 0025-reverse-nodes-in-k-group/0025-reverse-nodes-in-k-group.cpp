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
    ListNode* reverseLL(ListNode *head) {
        ListNode* next = NULL;
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode *itr = head;
        ListNode *prev = head;
        while (itr && cnt < k) {
            cnt++;
            prev = itr;
            itr = itr->next;
        }
        if (cnt != k) return head;
        prev->next = NULL;
        ListNode* curHead = reverseKGroup(itr, k);
        ListNode* returnedHead = reverseLL(head);
        head->next = curHead;
        return returnedHead;
    }
};