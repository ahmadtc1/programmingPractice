class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> nums;
        ListNode* current = head;
        while (current != nullptr) {
            nums.push_back(current -> val);
            current = current -> next;
        }
        int sum = 0;
        int exp = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            sum += ( nums[i] * pow(2, exp));
            exp++;
        }
        return sum;
    }
};
