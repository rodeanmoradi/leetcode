class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(end >= start) {
            int mid = (start + end) / 2;
            if(nums[start] == target) {
                return start;
            }
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[end] == target) {
                return end;
            }

            if(nums[start] < nums[mid] && target <= nums[mid] && target >= nums[start]) {
                end = mid - 1;
            }
            else if(nums[mid] < nums[end] && target <= nums[end] && target >= nums[mid]) {
                start = mid + 1;
            }
            else if(nums[start] < nums[mid]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return -1;
    }
};
