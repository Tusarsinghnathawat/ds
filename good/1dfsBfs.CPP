#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
vector<bool> vis(N);

// DFS‐based search: returns true if `target` is found within `limit` nodes examined.
bool dfs_search(int node, int target, int &limit, int &count) {
    if (count >= limit) return false;      // exhausted limit
    if (node == target) return true;       // found target

    vis[node] = true;
    count++;

    for (int nbr : adj[node]) {
        if (!vis[nbr] && count < limit) {
            if (dfs_search(nbr, target, limit, count))
                return true;               // propagate success
        }
    }
    return false;  // not found in this branch
}

// BFS‐based search: returns true if `target` is found within `limit` nodes examined.
bool bfs_search(int start, int target, int limit) {
    queue<int> q;
    fill(vis.begin(), vis.end(), false);
    q.push(start);
    vis[start] = true;
    int count = 0;

    while (!q.empty() && count < limit) {
        int node = q.front(); q.pop();
        if (node == target) return true;   // found target

        count++;
        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                vis[nbr] = true;
                q.push(nbr);
            }
        }
    }
    return false;  // not found within limit
}

void solve() {
    int n, m;
    cin >> n >> m;

    // build undirected graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int target, limit;
    cin >> target >> limit;

    // DFS search
    fill(vis.begin(), vis.end(), false);
    int dfsCount = 0;
    bool foundDFS = dfs_search(0, target, limit, dfsCount);
    cout << "DFS search " << (foundDFS ? "found " : "did not find ")
         << "node " << target
         << " within " << dfsCount << " node(s) examined.\n";

    // BFS search
    bool foundBFS = bfs_search(0, target, limit);
    // In BFS we counted internally; for simplicity, just report hit/miss:
    cout << "BFS search " << (foundBFS ? "found " : "did not find ")
         << "node " << target
         << " within " << limit << " node(s) examined.\n";
}

int main() {
    // fast IO is optional—remove these two lines if you prefer
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
