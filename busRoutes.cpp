#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int d;
int arr[100000000];

void solve() {
    
    std::cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    long long latestStartingDay = (long long)d;
    for (int i = n - 1; i >= 0; --i) {
        if (latestStartingDay % arr[i] == 0) {
        }
        else if (latestStartingDay % arr[i] != 0) {
            int divisor = latestStartingDay / arr[i];
            latestStartingDay = arr[i] * divisor;
        }
    }
    std::cout << latestStartingDay << std::endl;
    
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; ++i) {
	    std::cout << "Case # " << i+ 1 << ": ";
	}
}
