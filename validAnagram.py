class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        lettCountS = {}
        lettCountT = {}
        if len(s) != len(t):
            return False
        
        for x in range(len(s)):
            if s[x] in lettCountS:
                lettCountS[s[x]] += 1
            
            else:
                lettCountS[s[x]] = 1
                
            if t[x] in lettCountT:
                lettCountT[t[x]] += 1
                
            else:
                lettCountT[t[x]] = 1
                
        for letterCount in lettCountS:
            if letterCount not in lettCountS or letterCount not in lettCountT:
                return False
            
            if lettCountS[letterCount] != lettCountT[letterCount]:
                return False
            
        return True
