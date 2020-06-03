class Solution:
    def takeFirst(elem):
        return elem[0]
    
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        euclideans = []
        for x in range(len(points)):
            euclidean = 0.0
            squared = 0.0 + points[x][0]**2.0 + points[x][1]**2.0
            euclideans.append([math.sqrt(squared), x])
            
        euclideans.sort(key=lambda x: x[0])
        
        kClosest = []
        for x in range(K):
            kClosest.append(points[euclideans[x][1]])
            
        return kClosest
            
            
                
        
