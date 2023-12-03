/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(0);
        Node *temp = dummy;
        unordered_map<Node *, Node *>oldToNew;
        oldToNew[NULL] = NULL;
        Node *itr = head;
        while (itr) {
            Node *nn = new Node(itr->val);
            temp->next = nn;
            oldToNew[itr] = nn;
            itr = itr->next;
            temp = temp->next;
        }
        auto tempH = head;
        temp = dummy->next;
        while (tempH) {
            temp->random = oldToNew[tempH->random];
            tempH = tempH->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};