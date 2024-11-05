// graph - node (entity to store data), edge (connecting nodes)
// type - directed , undirected
// degree of node - no of edges connected to that node
// weighted graph - edges have some no on them
// path - going from one node to other node without passing a node more than once
// cyclic graph (directed) - starting node and end node is same while traversing
// Name: Lokendra Kushwah (7232)
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int node;
    vector<vector<int>> adj;
    vector<bool> visited;

    public:
    Graph(int node){
        this->node=node;
        adj.resize(node+1, vector<int>(node+1, 0));
        visited.resize(node, false);
    }

    void addEdge(int u, int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }

    void DFS(int vertex){
        visited[vertex] = true;
        cout<<vertex<<" ";

        for(int i=0; i<node; i++){
            if(adj[vertex][i] && !visited[i]){
                DFS(i);
            }
        }
    }

    void BFS(int vertex){
        queue<int>q;
        visited.assign(node, false);
        cout<<vertex<<" ";
        q.push(vertex);
        visited[vertex]=true;

        while(!q.empty()){
            int temp=q.front();
            q.pop();

            visited[temp]=true;
            for(int i=0; i<node; i++){
                if(adj[temp][i] && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                    cout<<i<<" ";
                }
            }
        }
    }
};

int main(){
    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;
    Graph G(n);
    
    while(n--){
        int u,v;
        cin>>u>>v;
        G.addEdge(u, v);
    }
    cout<<"Enter the vertex from which you have to traverse: ";
    int t; cin>>t;
    cout<<"DFS Traversal: ";
    G.DFS(t);
    cout<<endl;
    cout<<"BFS Traversal: ";
    G.BFS(t);
    cout<<endl;
}

// Input
// 6
// 1 2
// 2 3
// 2 5
// 5 6
// 3 4
// 6 4