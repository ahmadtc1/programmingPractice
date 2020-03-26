class Solution:
    def defangIPaddr(self, address: str) -> str:
        defangledAddress = ""
        for letter in address:
            if (letter == "."):
                defangledAddress += "[.]"
            else:
                defangledAddress += letter
        return defangledAddress
            
