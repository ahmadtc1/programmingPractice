class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min = sys.maxsize
        largestProfit = 0
        for price in prices:
            if price < min:
                min = price
                
            elif (price - min) > largestProfit:
                largestProfit = price - min
        return largestProfit
