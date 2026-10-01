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

        vector<int> a1 = {};
        vector<int>& a1r = a1;
        vector<int> a2 = {};
        vector<int>& a2r = a2;
        traverseTree(p, a1r);
        traverseTree(q, a2r);
        if (a1.size() == a2.size()) {
            for (int i{}; i < a1.size(); i++) {
                if (a1[i] == a2[i]) continue;
                return false;
            }
        }
        else return false;
        return true;
    }
};
