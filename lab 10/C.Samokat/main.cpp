#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector <int> used;
vector <int> comp;

bool dfs(int v, int t){
    used[v]=1;
    if (v==t){
        return true;
    }
    for (int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        if (!used[to]){
            if (dfs(to,t)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int q, n, m, v1, v2;
    int v,t;
    cin >> n >> m >> q;
    g.resize(n, vector<int> ());
    used.resize(n, 0);
    comp.resize(n, 0);
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        g[v1-1].push_back(v2-1);
    }
    for (int i = 0; i < q; i++){
        bool p1, p2;
        cin >> v >> t;
        v--;
        t--;
        fill(used.begin(), used.end(), 0);
        p1 = dfs(v,t);
        fill(used.begin(), used.end(), 0);
        p2 = dfs(t,v);
        if (p1 && p2){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
