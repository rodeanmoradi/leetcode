class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (right > left) {
            int water = (right - left) * std::min(heights[left], heights[right]);
            if (water > max_water) {
                max_water = water;
            }
            
            if (heights[left] > heights[right]) {
                right -= 1;
            }
            else {
                left += 1;
            }
        }

        return max_water;
    }
};
