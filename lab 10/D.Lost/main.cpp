#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector <bool> used;
vector <int> ans;
int curMax;

void dfs(int v){
    used[v]=true;
    for (int i=0; i<g[v].size(); i++){
        if (used[g[v][i]] == 0)
            dfs(g[v][i]);
    }
    ans[v] = curMax;
    curMax--;
}


void TopSort(int n){
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs(i);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] <<' ';
}


int main() {
    int n, m, v1, v2;
    cin >> n >> m;
    curMax = n;
    g.resize(n, vector<int> ());
    used.resize(n, false);
    ans.resize(n, 0);
    for (int i = 0; i < n; i++)
        ans[i] = i + 1;
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        g[v1-1].push_back(v2-1);
    }
    TopSort(n);
    return 0;
}
