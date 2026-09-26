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
public:
    bool hasCycle(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        while(head != nullptr) {
            if (f->next == nullptr || f->next->next == nullptr) break;
            s = s->next;
            f = f->next->next;
            if (s == f) return true;
        }
        return false;
    }
};
