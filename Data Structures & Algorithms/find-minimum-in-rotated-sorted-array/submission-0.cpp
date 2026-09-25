class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = 0;
        int min = nums[0];
        for (int num : nums) {
            if (num < min) {
                min = num;
            }
        }

        return min;
    }
};
