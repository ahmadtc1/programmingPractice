class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutesCount = 0;
        bool allRotten = false;
        while (!allRotten) {
            allRotten = true;
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    std::cout << grid[i][j];
                    if (grid[i][j] == 1) {
                        allRotten = false;
                    }
                }
            }
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (grid[i][j] == 2) {
                        if (i - 1 >= 0) {
                            if (grid[i-1][j] != 0) {
                                grid[i-1][j] = 2;
                            }
                        }
                        if (i + 1 <= grid.size()) {
                            if (grid[i+1][j] != 0) {
                                grid[i+1][j] = 2;
                            }
                        }
                        if (j - 1 >= 0) {
                            if (grid[i][j-1] != 0) {
                                grid[i][j-1] = 2;
                            }
                        }
                        if (j + 1 <= grid[0].size()) {
                            if (grid[i][j+1] != 0) {
                                grid[i][j+1] = 2;
                            }
                        }
                    }
                }
            }
            minutesCount++;
        }
        return minutesCount;
    }
};
