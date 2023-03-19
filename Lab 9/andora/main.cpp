#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> used;
vector<vector<int>> g;
vector <int> dist;

struct Object{
    int x, y, z;
    int h;
};



void bfs(int s){
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    used[s] = 1;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++){
            if (used[g[v][i]]==0){
                dist[g[v][i]] = dist[v] + 1;
                used[g[v][i]] = 1;
                q.push(g[v][i]);
            }
        }
    }
}
int main() {
    int n,m;
    int v1, v2;
    int s,f;
    cin >> n >> m;
    g.resize(n , vector<int> ());
    used.resize(n,0);
    dist.resize(n, -1);
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        g[v1-1].push_back(v2-1);
        g[v2-1].push_back(v1-1);
    }
    cin >> s >> f;
    s--;
    f--;
    bfs(s);
    cout << dist[f] << ' ';
    return 0;
}
