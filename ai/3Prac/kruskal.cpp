//jai bajrang bali
#include <bits/stdc++.h>
using namespace std;

#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
const int INF = 1e18;


class dsu{
    vector<int> rank, parent, size;

    public:
        dsu(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

void solve() {
   

    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    dsu ds(N);

    int mst_weight = 0;

    vector<pair<int, int>> mst_edges;

    for (auto it: edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUPar(u) != ds.findUPar(v)) {
            mst_weight += wt;
            mst_edges.push_back({u, v});
            ds.unionByRank(u, v);
        }
    }

    cout << "MST total weight: " << mst_weight << "\n";
    cout << "Edges in the MST:\n";
    for (auto it : mst_edges) {
        int u = it.first;
        int v = it.second;
        cout << u << " - " << v << "\n";
    }

}

signed main() {
    Sachin_3059
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}