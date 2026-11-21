class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0
        r = len(heights) - 1
        max_area = min(heights[l], heights[r]) * (r - l)
        for _ in heights:
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
            a = min(heights[l], heights[r]) * (r - l)
            if a > max_area:
                max_area = a
        return max_area
        