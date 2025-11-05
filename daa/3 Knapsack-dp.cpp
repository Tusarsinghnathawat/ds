#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items (n): ";
    cin >> n;

    vector<int> weight(n + 1), profit(n + 1);
    cout << "Enter weights and profits of items (w, p):\n";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter maximum capacity of knapsack (W): ";
    cin >> W;

    // DP table where dp[i][w] = max profit using first i items and capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i] <= w)
                dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "\nMaximum Profit: " << dp[n][W] << endl;

    // Trace selected items
    int w = W;
    cout << "Items included: ";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i];
        }
    }
    cout << endl;

    return 0;
}

// Time: O(n × W) 
// Enter number of items (n): 3
// Enter weights and profits of items (w, p):
// 2 12
// 6 5
// 3 7
// Enter maximum capacity of knapsack (W): 4

// Maximum Profit: 12
// Items included: 1 