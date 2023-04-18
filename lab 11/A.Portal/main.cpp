#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e12;

struct Edge {
    int to;
    long long cost;
};

struct Node {
    int pos;
    long long dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

long long bfs(vector<vector<Edge>>& adj, int start, int end, int k) {
    vector<long long> dist(adj.size(), INF);
    dist[start] = 0;
    priority_queue<Node> q;
    q.push({start, 0});
    while (!q.empty()) {
        int node = q.top().pos;
        long long curDist = q.top().dist;
        q.pop();

        if (curDist > dist[node]) {
            continue;
        }

        for (auto edge : adj[node]) {
            if (abs(edge.to - node) > k and node != start) {
                continue;
            }
            long long new_dist = curDist + edge.cost;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;
                q.push({edge.to, new_dist});
            }
        }
    }
    if (dist[end] == INF) {
        return -1;
    }
    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        long long dist = bfs(g, u, v, k);
        cout << dist << endl;
    }

    return 0;
}