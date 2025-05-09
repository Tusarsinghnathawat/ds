#include <bits/stdc++.h>
using namespace std;

// Define infinity as a large enough value
const int INF = 1e9;
vector<vector<pair<int, int>>> adj; // Adjacency list (graph representation)

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(int n, int src) {
    // Distance vector to store the shortest distance from source
    vector<int> dist(n, INF);
    dist[src] = 0;

    // Min-heap priority queue to store (distance, node) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();

        // If the current distance is greater than the recorded one, skip it
        if (uDist > dist[u]) continue;

        // Explore neighbors of the current node
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;   // Neighbor node
            int weight = neighbor.second; // Edge weight

            // Relaxation step: update the distance if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist; // Return the distance vector
}

// Function to print the shortest path distances
void printShortestPaths(int n, const vector<int>& dist) {
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "Node " << i << ": No path from source\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    adj.resize(n); // Initialize the adjacency list with n vertices

    cout << "Enter the edges (u, v, w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Add edge u -> v with weight w
        adj[v].push_back({u, w}); // Add edge v -> u (undirected graph)
    }

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    // Run Dijkstra's algorithm from the source
    vector<int> dist = dijkstra(n, src);

    // Output the shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    printShortestPaths(n, dist);

    return 0;
}
