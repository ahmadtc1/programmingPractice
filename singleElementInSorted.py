class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        numCount = {}
        for num in nums:
            if num in numCount:
                numCount[num] += 1
            else:
                numCount[num] = 1
                
        for num in numCount:
            if numCount[num] == 1:
                return num
            
        return 0
        
