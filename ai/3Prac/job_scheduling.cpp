//jai bajrang bali
#include <bits/stdc++.h>
using namespace std;

#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
const int INF = 1e18;

vector<int>adj[N];


// job scheduling => topological sort  1. kah'n algo 2. dfs
// apply only on DAG(directed acyclic graph)
// a->b    a comes first than b;


void kahn_algo(int n) {
    vector<int> in_degree(n + 1, 0);
    queue<int> q;
    vector<int> top_order;

    // Calculate in-degree for each node
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            in_degree[v]++;
        }
    }

    // Enqueue nodes with in-degree 0
    for (int u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        // Reduce in-degree for all neighbors
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
        cnt++;
    }

    // Check for cycles
    if (cnt != n) {
        cout << "Graph has a cycle!\n";
        return;
    }

    // Print topological order
    for (int u : top_order) {
        cout << u << " ";
    }
    cout << "\n";
}

void solve() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    kahn_algo(n);



}

signed main() {
    Sachin_3059
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}