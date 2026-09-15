class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        std::unordered_map<string, int> strs_map;
        for (int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            std::sort(copy.begin(), copy.end());
            if (!strs_map.contains(copy)) {
                vector<string> group;
                group.push_back(strs[i]);
                groups.push_back(group);
                strs_map[copy] = groups.size() - 1;
            }
            else {
                int idx = strs_map[copy];
                groups[idx].push_back(strs[i]);
            }
        }

        return groups;
    }
};
