#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

bool solve(vector<vector<pair<int, int>>>& adj_list, int n, int k) {
	vector<int> distances(n, INF);
	distances[0] = 0;

	for (int i = 0; i < n; i++) {
		bool updated = false;
		for (int u = 0; u < n; u++) {
			for (auto edge : adj_list[u]) {
				int v = edge.first;
				int weight = edge.second;
				if (distances[u] != INF && distances[u] + weight < distances[v]) {
					distances[v] = distances[u] + weight;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}

	int cycle_length = 0;
	for (int u = 0; u < n; u++) {
		for (auto edge : adj_list[u]) {
			int v = edge.first;
			int weight = edge.second;
			if (distances[u] != INF && distances[u] + weight < distances[v]) {
				cycle_length++;
			}
		}
	}

	return cycle_length <= k;
}

int main() {
	int N, k;
	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		int n, m;
		cin >> n >> m;

		vector<vector<pair<int, int>>> adj_list(n);
		for (int j = 0; j < m; j++) {
			int start, end, w;
			cin >> start >> end >> w;
			start--;
			end--;
			adj_list[start].push_back({end, w});
		}

		if (solve(adj_list, n, k))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}