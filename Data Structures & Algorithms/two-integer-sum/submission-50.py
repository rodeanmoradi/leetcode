class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i in range(len(nums)):
            # iterate, put num in hash map
            # compute difference, if difference in map, return the indices
            if nums[i] not in m:
                m[nums[i]] = i
            d = target - nums[i]
            if d in m and m[d] != i:
                return [m[d], i]