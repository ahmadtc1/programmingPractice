class Solution:
    def climbStairs(self, n: int) -> int:
        #calculate the unique ways to reach each step
        #add up these values to determine the unique ways to reach the top step
        distinctWays = [None] * (n + 1)
        distinctWays[0] = 0
        distinctWays[1] = 1
        if (n >= 2):
            distinctWays[2] = 2
        for x in range(3, n+1):
            distinctWays[x] = distinctWays[x-1] + distinctWays[x-2]
        return distinctWays[n]
