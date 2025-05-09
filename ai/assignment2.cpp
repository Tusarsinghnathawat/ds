#include <bits/stdc++.h>
using namespace std;

#define N 3

struct Puzzle {
    vector<vector<int>> mat;
    int x, y;  // position of 0
    int cost, level;
    string path;

    bool operator>(const Puzzle& other) const {
        return (cost + level) > (other.cost + other.level);
    }
};

vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string dir = "UDLR";

// Heuristic: Manhattan Distance
int calculateCost(vector<vector<int>>& initial) {
    int cost = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] != 0) {
                int val = initial[i][j] - 1;
                cost += abs(i - val / N) + abs(j - val % N);
            }
    return cost;
}

// Check if position is valid
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Check if current state is goal
bool isGoal(vector<vector<int>>& mat) {
    return mat == goal;
}

// A* algorithm
void solve(vector<vector<int>> initial, int x, int y) {
    priority_queue<Puzzle, vector<Puzzle>, greater<Puzzle>> pq;

    set<vector<vector<int>>> visited;

    Puzzle start = {initial, x, y, calculateCost(initial), 0, ""};
    pq.push(start);

    while (!pq.empty()) {
        Puzzle curr = pq.top(); pq.pop();

        if (visited.count(curr.mat)) continue;
        visited.insert(curr.mat);

        if (isGoal(curr.mat)) {
            cout << "Reached goal in " << curr.level << " moves.\n";
            cout << "Moves: " << curr.path << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isValid(newX, newY)) {
                vector<vector<int>> newMat = curr.mat;
                swap(newMat[curr.x][curr.y], newMat[newX][newY]);

                if (!visited.count(newMat)) {
                    Puzzle child = {
                        newMat,
                        newX,
                        newY,
                        calculateCost(newMat),
                        curr.level + 1,
                        curr.path + dir[i]
                    };
                    pq.push(child);
                }
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    // Example initial state
    vector<vector<int>> initial = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    // Find position of 0 (blank)
    int x, y;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (initial[i][j] == 0) {
                x = i;
                y = j;
            }

    solve(initial, x, y);

    return 0;
}
