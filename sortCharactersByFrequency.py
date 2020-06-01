class Solution:
    def frequencySort(self, s: str) -> str:
        returnString = ""
        letterCount = {}
        for letter in s:
            if letter in letterCount:
                letterCount[letter] += 1
            else:
                letterCount[letter] = 1
                
        for letter in sorted(letterCount, key=letterCount.get, reverse=True):
            letterString = letterCount[letter] * letter
            returnString += letterString
            letterString = 0
            
        return returnString
