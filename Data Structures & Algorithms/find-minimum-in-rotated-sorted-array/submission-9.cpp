class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int min = nums[0];
        while (l <= r) {
            if (nums[l] < min) min = nums[l];
            int m = (l + r) / 2;
            if (nums[l] > nums[m]) {
                if (nums[m] < min) min = nums[m];
                r = m - 1;
            }
            else if (nums[m] > nums[r]) {
                if (nums[m] < min) min = nums[m];
                l = m + 1;
            }
            else return min;
        }

        return min;
    }
};
