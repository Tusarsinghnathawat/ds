//jai bajrang bali
#include <bits/stdc++.h>
using namespace std;

#define Sachin_3059 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
const int INF = 1e18;



void solve() {
    int n; cin >> n;
    vector<int>arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        int mn = arr[i];
        int id = i;
        for(int j = i; j < n; j++){
            if(arr[j] < mn){
                mn = arr[j];
                id = j;
            }
        }

        swap(arr[i], arr[id]);
    }

    cout << "selection sort: " ;
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
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