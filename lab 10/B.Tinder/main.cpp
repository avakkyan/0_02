#include <iostream>
#include <vector>
#include <algorithm>
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
    char move;
    cin >> n >> m >> q;
    g.resize(n, vector<int> ());
    used.resize(n, 0);
    comp.resize(n, 0);
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        g[v1-1].push_back(v2-1);
        g[v2-1].push_back(v1-1);

    }
    for (int i=0; i<q; i++){
        cin >> move >> v >> t;
        if (move == '?'){
            bool p1;
            fill(used.begin(), used.end(), 0);
            p1 = dfs(v-1,t-1);
            if (p1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        if (move == '-'){
            vector<int>::iterator new_end1;
            new_end1 = remove(g[v-1].begin(),g[v-1].end(),t-1);
            g[v-1].erase(new_end1, g[v-1].end());
            vector<int>::iterator new_end2;
            new_end2 = remove(g[t-1].begin(),g[t-1].end(),v-1);
            g[t-1].erase(new_end2, g[t-1].end());
        }
    }
    return 0;
}
