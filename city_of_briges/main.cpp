#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector <int> used;
vector <int> comp;
vector <int> parent;
int component = 0;
bool cycle = false;

void dfs(int v){
    used[v]=1;
    for (int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        if (used[to] == 0){
            parent[to] = v;
            dfs(to);
        }
        else if (used[to] == 1 && to != parent[v]){
            cycle = true;
        }
    }
    used [v] = 2;
}

int main() {
    int n, m, v1, v2;
    cin >> n >> m;
    g.resize(n, vector<int> ());
    used.resize(n, 0);
    comp.resize(n, 0);
    parent.resize(n, 0);
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        g[v1-1].push_back(v2-1);
        g[v2-1].push_back(v1-1);
    }
    for (int i = 0; i < n; i++){
        if (!used[i]) {
            dfs(i);
        }
    }

    if (cycle){
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}
