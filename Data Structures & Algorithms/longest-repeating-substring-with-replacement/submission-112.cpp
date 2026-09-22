class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (char letter : alphabet) {
            int l = 0;
            int r = 0;
            int others = 0;
            int len = 0;
            while ((r < s.size()) && !(l == r && r == s.size() - 1)) {
                if ((r < s.size()) && (s[r] == letter)) {
                    len = r - l + 1;
                    if (len > res) {
                        res = len;
                    }
                    r++;
                }
                else {
                    others++;
                    if (others <= k) {
                        len = r - l + 1;
                        if (len > res) {
                            res = len;
                        }
                        r++;
                    }
                    else {
                        while (others > k) {
                            if ((l < s.size()) && (s[l] == letter)) {
                                l++;
                            }
                            else {
                                others = 0;
                                l++;
                                r = l;

                                if (l > r) return res;
                            }
                        }
                    }
                }
                if (res == s.size()) return res;
            }
        }

        if (s.size() == 1) return 1;

        return res;
    }
};
