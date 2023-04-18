#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e6;

vector<pair<int, int>> adj[MAXN];
int dist[MAXN];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dist[u]) {
			continue;
		}

		for (auto& edge : adj[u]) {
			int v = edge.first;
			int w = edge.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, q, s;
	cin >> n >> m >> q >> s;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
	}

	fill(dist, dist + MAXN, INF);
	dijkstra(s);
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (dist[t] == INF)
			cout << -1 << "\n";
		else
			cout << dist[t] << "\n";
	}

	return 0;
}