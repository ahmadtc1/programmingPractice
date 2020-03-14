class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsDict = {}
        for i in range(len(nums)):
            if (target - nums[i]) in numsDict:
                twoElements = [numsDict[target-nums[i]], i]
                return twoElements
            else:
                numsDict[nums[i]] = i
        
