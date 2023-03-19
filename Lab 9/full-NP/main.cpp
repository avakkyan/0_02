#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector <int> used;
vector <int> parent;
bool cycle = false;
vector <int> visited;

void dfs(int v, int d){
    used[v]=1;
    d++;
    visited[v] = visited[v]+d;
    for (int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        if (used[to] == 0){
            parent[to] = v;
            dfs(to, d);
        }
        else if (used[to] == 1 && to != parent[v]){
            cycle = true;
        }
    }
    used [v] = 2;
}
int main() {
    int max;
    int n, m, v1, v2;
    cin >> n >> m;
    int d=0;
    g.resize(n, vector<int> ());
    used.resize(n, 0);
    parent.resize(n, 0);
    visited.resize(n, 0);
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        g[v1-1].push_back(v2-1);
        g[v2-1].push_back(v1-1);
    }
    dfs(0, d);
    int last;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] > max) {
            max = visited[i];
            //cout << visited[i];
            last = i;
        }
    }
    for (int i = 0; i < used.size(); i++) {
        used[i]=0;
    }

    for (int i = 0; i < visited.size(); i++) {
        visited[i]=0;
    }
    d=0;
    dfs(last, d);
    //cout << visited.size();
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] > max) {
            max = visited[i];
            //cout << visited[i];
        }
    }
    if (max == n) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
