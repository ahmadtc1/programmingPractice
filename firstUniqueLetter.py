class Solution:
    def firstUniqChar(self, s: str) -> int:
        if (len(s) == 0):
            return -1
        letterCount = {}
        for i in range(len(s)):
            if s[i] in letterCount:
                letterCount[s[i]][1] += 1
            else:
                letterCount[s[i]] = [i, 1]
        minUniqueCharacterIndex = sys.maxsize
        for key in letterCount:
            if letterCount[key][1] == 1:
                if letterCount[key][0] < minUniqueCharacterIndex:
                    minUniqueCharacterIndex = letterCount[key][0]
        if (minUniqueCharacterIndex == sys.maxsize):
            return -1
        return minUniqueCharacterIndex
