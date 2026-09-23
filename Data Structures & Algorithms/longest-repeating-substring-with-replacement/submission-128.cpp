class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int l = 0;
        int r = 0;
        int res = 0;
        int len = 0;
        int max = 0;
        while (r < s.size()) {
            if (counts.contains(s[r])) counts[s[r]]++; else counts[s[r]] = 1;
            for (const auto& [k, v] : counts) {
                if (v > max) max = v;
            }

            int replacements = (r - l + 1) - max;
            if (replacements <= k) {
                len = r - l + 1;
                if (len > res) res = len;
                r++;
            }
            else {
                counts[s[l]]--;
                l++;
                counts[s[r]]--;
            }
        }

        return res;
    }
};
