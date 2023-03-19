#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector <int> used;

int component = 0;

void dfs(int v){
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (!used[to]){
            dfs(to);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int k=0;
    char flat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> flat[i][j];
            if (flat[i][j]== '.'){
                k++;
            }
        }
    }
    g.resize(m*n , vector<int> ());
    used.resize(n*m,-1);
    for (int i = 0; i < n; i++) {
        for (int j = 0;  j < m; j++) {

            if (flat[i][j]  == '.') {
                used[i*m+j] = 0;
                if (flat[i - 1][j]  == '.' ) {
                    g[(i)*m+j].push_back((i-1)*m+j);

                }
                if (flat[i][j-1]  == '.' ) {
                    g[i*m+(j)].push_back(i*m+(j-1));

                }
                if (flat[i][j+1]  == '.' ) {
                    g[i*m+(j)].push_back(i*m+(j+1));

                }
                if (flat[i+1][j]  == '.' ) {
                    g[(i)*m+j].push_back((i+1)*m+j);

                }
            }
        }
    }
//    for (int i = 0; i < n*m; i++) {
//        for (int j = 0; j < g[i].size(); j++) {
//            cout << g[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    for (int i = 0; i < used.size(); i++){
        if (used[i] == 0) {
            component++;
            dfs(i);

        }
    }
   cout << component;

    return 0;
}
