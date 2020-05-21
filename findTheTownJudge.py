class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        if (len(trust) == 0 and N == 1):
            return 1
        elif (len(trust) == 0 and N > 1):
            return -1
        
        trusting = {-1}
        trustCount = {}
        for t in trust:
            trusting.add(t[0])
            if (t[1] in trustCount):
                trustCount[t[1]] += 1
            else:
                trustCount[t[1]] = 1
                
        for trustee in trustCount:
            if ((trustCount[trustee] == (N - 1)) and trustee not in trusting):
                return trustee
            
        return -1
        
        
