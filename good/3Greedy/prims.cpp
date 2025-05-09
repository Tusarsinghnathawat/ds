#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int dest;
    int weight;
};

struct Node {
    int vertex;
    int key;
    bool operator>(const Node& other) const {
        return key > other.key;
    }
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adjList;

    Graph(int V);
    void addEdge(int u, int v, int weight);
    void primMST();
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});
}

void Graph::primMST() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        inMST[u] = true;

        for (const Edge& edge : adjList[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({v, key[v]});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " -- " << i << " == " << key[i] << endl;
    }
}

int main() {
    Graph g(6);  // Number of vertices in the graph

    // Add edges (u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(4, 5, 3);
    g.addEdge(5, 6, 1);

    // Find MST using Prim's algorithm
    g.primMST();

    return 0;
}
