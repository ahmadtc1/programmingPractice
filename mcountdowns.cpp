#include <iostream>
#include <vector>


void solve(std::vector<int> a, int n) {
    int countDowns = 0;
    bool isCountdown = false;
    for (int i = 0; i < n - 1; ++i) {
        if ((isCountdown && (a[i] - 1) != a[i+1]) || (isCountdown && i == n - 2)) {
            countDowns ++;
            isCountdown = false;
        }
        else if (a[i] == a[i+1] + 1) {
            isCountdown = true;
        }
    }
    std::cout << countDowns << std::endl;
}


int main() {
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(7);
	a.push_back(9);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(8);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	
	solve(a, a.size());
}
