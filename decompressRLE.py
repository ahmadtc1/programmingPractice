class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        masterList = []
        for i in range(len(nums)):
            if (i % 2 == 0):
                list = []
                
                for j in range(nums[i]):
                    list.append(nums[i+1])
                
                masterList += list
        return masterList
