class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a map of num : occurrences
        unordered_map<int, int> nums_map;
        for (int num : nums) {
            if (nums_map.contains(num)) nums_map[num]++;
            else nums_map[num] = 1;
        }

        // create an array whose indexes are num occurr. and vals
        // are the corresponding num(s)
        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& [k, v] : nums_map) {
            bucket[v].push_back(k);
        }

        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int val: bucket[i]) {
                if (nums_map.contains(val)) {
                    result.push_back(val);
                    if (result.size() == k) return result;
                }
            }
        }

        return result;
    }
};
