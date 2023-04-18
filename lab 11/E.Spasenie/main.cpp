#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
struct Edge{
	int to;
	int cost;
};

int main(){
	int n, m, s, f;
	cin >> n >> m >> s >> f;

	s--;
	f--;

	vector<vector<Edge>> g(n);
	for (int i = 0; i < m; i++){
		int a, b, x;
		cin >> a >> b >> x;
		a--; b--;
		Edge q = {b, x};
		g[a].push_back(q);
	}

	vector<int> d(n, INF), p(n);
	d[s] = 0;
	set<pair<int,int>> q;
	q.insert ({d[s], s});

	while (!q.empty()) {
		pair<int, int> v = *q.begin();
		q.erase(q.begin());
		for(int j = 0; j < g[v.second].size(); j++){
			int to = g[v.second][j].to;
			int len = g[v.second][j].cost;
			if (d[g[v.second][j].to] > v.first + g[v.second][j].cost){
				q.erase({d[to], to});
				d[to] = d[v.second] + len;
				p[to] = v.second;
				q.insert({d[to], to});
			}
		}
	}

	if (d[f] != INF)
		cout << d[f];
	else
		cout << -1;

	return 0;
}