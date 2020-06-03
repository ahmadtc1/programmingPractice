class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int smallerHeight;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                smallerHeight = (height[j] > height[i]) ? height[i]: height[j];
                if (maxArea < ((j - i) * smallerHeight)) {
                    maxArea = ((j - i) * smallerHeight);
                }
            }
        } 
        return maxArea;
    }
};
