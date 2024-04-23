// Given sequence k = k1 <k2 < ... < kn of n sorted keys, with a search probability pi for each
// key ki . Build the Binary search tree that has the least search cost given the access probability
// for each key.

#include <iostream>
#include <vector>

using namespace std;

class OBST {
public:
    vector<vector<double>> cost; // cost[i][j] represents the cost of searching keys from i to j
    vector<vector<double>> weighted; // weighted[i][j] represents the sum of access probabilities from i to j
    vector<int> keys;
    vector<double> probabilities;

    OBST(vector<int>& keys, vector<double>& probabilities) : keys(keys), probabilities(probabilities) {
        int n = keys.size();
        cost.resize(n, vector<double>(n, 0));
        weighted.resize(n, vector<double>(n, 0));

        // Initialize weighted array
        for (int i = 0; i < n; ++i)
            weighted[i][i] = probabilities[i];

        // Calculate weighted sum of probabilities for each subsequence
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i <= n - L + 1; ++i) {
                int j = i + L - 1;
                weighted[i][j] = weighted[i][j - 1] + probabilities[j];
            }
        }

        // Fill the cost matrix using dynamic programming
        for (int L = 1; L <= n; ++L) {
            for (int i = 0; i <= n - L + 1; ++i) {
                int j = i + L - 1;
                cost[i][j] = INT_MAX;

                // Try making each key the root and recursively calculate cost
                for (int r = i; r <= j; ++r) {
                    double c = ((r > i) ? cost[i][r - 1] : 0) +
                               ((r < j) ? cost[r + 1][j] : 0) +
                               weighted[i][j];

                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                    }
                }
            }
        }
    }

    double getMinCost() {
        return cost[0][keys.size() - 1];
    }
};

int main() {
    vector<int> keys = {10, 12, 20};
    vector<double> probabilities = {0.34, 0.33, 0.33};

    OBST obst(keys, probabilities);
    cout << "Minimum search cost: " << obst.getMinCost() << endl;

    return 0;
}
