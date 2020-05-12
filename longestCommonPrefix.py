class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        longestPrefix = ""
        if (len(strs) > 0):
            sameLetter = True
            index = 0
            while (sameLetter):
                if (len(strs[0]) > index):
                    letter = strs[0][index]
                else:
                    sameLetter = False
                    letter = ""
                    
                for word in strs:
                    if (len(word) > index):
                        if (word[index] != letter):
                            sameLetter = False
                    else:
                        sameLetter = False
                if (sameLetter):
                    longestPrefix += letter
                    index += 1
        return longestPrefix
