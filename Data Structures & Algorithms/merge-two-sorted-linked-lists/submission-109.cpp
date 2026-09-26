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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* node = new ListNode();
        ListNode* head = node;
        ListNode* cur = head;
        if (cur1 == nullptr) return cur2;
        if (cur2 == nullptr) return cur1;
        while (!(cur1 == nullptr && cur2 == nullptr)) {
            if (cur1 == nullptr) {
                cur->val = cur2->val;
                cur2 = cur2->next;
                if (cur1 == nullptr && cur2 == nullptr) return head;
                ListNode* new_node = new ListNode();
                cur->next = new_node;
                cur = cur->next; 
            }
            else if (cur2 == nullptr) {
                cur->val = cur1->val;
                cur1 = cur1->next;
                if (cur1 == nullptr && cur2 == nullptr) return head;
                ListNode* new_node = new ListNode();
                cur->next = new_node;
                cur = cur->next;
            }
            else if (cur1->val < cur2->val) {
                cur->val = cur1->val;
                cur1 = cur1->next;
                if (cur1 == nullptr && cur2 == nullptr) return head;
                ListNode* new_node = new ListNode();
                cur->next = new_node;
                cur = cur->next;
            }   
            else if (cur1->val >= cur2->val) {
                cur->val = cur2->val;
                cur2 = cur2->next;
                if (cur1 == nullptr && cur2 == nullptr) return head;
                ListNode* new_node = new ListNode();
                cur->next = new_node;
                cur = cur->next;
            }
        }
        return head;
    }
};
