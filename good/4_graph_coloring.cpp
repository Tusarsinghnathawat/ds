#include <iostream>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX]; // Adjacency matrix
int color[MAX];      // Color assigned to each vertex

// Function to check if the current color assignment is valid
bool isSafe(int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to color the graph
bool graphColoring(int v, int V, int m) {
    if (v == V) return true; // All vertices are colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, V)) {
            color[v] = c;

            if (graphColoring(v + 1, V, m)) return true;
            
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int V = 4; // Number of vertices
    int m = 3; // Number of colors

    // Example graph (adjacency matrix)
    int tempGraph[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    // Copy to graph array
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = tempGraph[i][j];

    // Initialize all colors to 0 (unassigned)
    for (int i = 0; i < V; i++) color[i] = 0;


// v → currentVertex — represents the vertex currently being colored.

// V → totalVertices — total number of vertices in the graph.

// m → maxColors — the maximum number of colors we can use.


    if (graphColoring(0, V, m)) {
        cout << "Solution exists. Colors assigned:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    } else {
        cout << "No solution exists with " << m << " colors.\n";
    }

    return 0;
}