class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rotated = nums;
        int size = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if ((i + k) < size) {
                rotated[i+k] = nums[i];
            }
            else if ((i + k) >= size) {
                rotated[(i + k) % size] = nums[i];
            }
        }
        nums = rotated;
    }
};
