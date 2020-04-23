/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {        
        if (!head || !head -> next) {
            return false;
        }
        
        ListNode* slowRunner = head;
        ListNode* fastRunner = head -> next;
        
        while (slowRunner != fastRunner) {
            if (fastRunner == nullptr || fastRunner -> next == nullptr) {
                return false;
            }
            slowRunner = slowRunner -> next;
            fastRunner = fastRunner -> next -> next;
        }
        return true;
    }
};
