class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (l < r) {
                if (nums[l] + nums[r] > target) {
                    r -= 1;
                }
                else if (nums[l] + nums[r] < target) {
                    l += 1;
                }
                else {
                    triplets.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l += 1;
                    }
                }
            }
        }

        return triplets;
    }
};
