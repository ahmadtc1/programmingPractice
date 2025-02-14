# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        listAContents = {}
        while headA != None:
            listAContents[headA] = 1
            headA = headA.next
            
        while headB != None:
            if headB in listAContents:
                return headB
            
            headB = headB.next
        
        return None
