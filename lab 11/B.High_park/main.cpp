#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		dist[u][v] = dist[v][u] = w;
	}
	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dist[i][j] == INF) {
				continue;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	if (ans == 0) {
		cout << ans << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}