class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        count = 0
        for letter in S:
            found = J.find(letter)
            if (found != -1):
                count += 1
        return count
