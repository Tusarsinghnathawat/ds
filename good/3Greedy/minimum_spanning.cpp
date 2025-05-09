#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compareEdges(const Edge& a, const Edge& b) { // Comparator for sorting edges by weight
    return a.weight < b.weight;
}

class DSU { // Disjoint Set Union
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;

        // Union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    DSU dsu(V);

    vector<Edge> mst;
    int totalWeight = 0;

    for (const Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
        }
    }

    cout << "Minimum Spanning Tree edges:\n";
    for (const Edge& e : mst) {
        cout << e.u << " - " << e.v << " (weight " << e.weight << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    kruskalMST(V, edges);

    return 0;
}
