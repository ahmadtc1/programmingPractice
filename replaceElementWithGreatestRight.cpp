class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i == arr.size() - 1) {
                arr[i] = -1;
            }
            else {
                for (int j = i + 1; j < arr.size(); ++j) {
                    if (arr[j] >= greatest) {
                        greatest = arr[j];
                    }
                }
                arr[i] = greatest;
                greatest = 0;
            }
        }
        return arr;
    }
};
