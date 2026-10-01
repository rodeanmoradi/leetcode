class Solution {
public:
    TreeNode* traverseTree(TreeNode* p, vector<int>& a) {
        if (p == nullptr) {
            a.push_back(0);
            return p;
        }

        a.push_back(p->val);
        traverseTree(p->left, a);
        traverseTree(p->right, a);
        return p;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr) return true;
        else if (p == nullptr or q == nullptr) return false;

        if (p->val != q->val) return false;

        vector<int> a1{};
        vector<int> a2{};
        traverseTree(p, a1);
        traverseTree(q, a2);
        if (a1 == a2) {
            return true;
        }
        return false;
    }
};
