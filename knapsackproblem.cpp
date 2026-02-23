#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]], // include item
                    dp[i - 1][w]                           // exclude item
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> wt = {1, 3, 4, 5};   // weights
    vector<int> val = {1, 4, 5, 7};  // values
    int W = 7;                      // capacity
    int n = wt.size();

    cout << "Maximum value: " << knapsack(W, wt, val, n);

    return 0;
}