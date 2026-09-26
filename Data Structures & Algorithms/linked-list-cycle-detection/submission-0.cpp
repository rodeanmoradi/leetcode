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
        ListNode* cur = head;
        unordered_map<ListNode*, int> visited;
        while (cur != nullptr) {
            if (visited.contains(cur)) return true;
            else {
                visited[cur] = 1;
                cur = cur->next;
            }
        }

        return false;
    }
};
