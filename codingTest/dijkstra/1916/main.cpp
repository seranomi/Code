#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 2147483647;

typedef pair<int, int> Node;

int N, M;
// {cost, node}
vector<vector<Node>> adj;
vector<int> dist;

int main() {
	cin >> N >> M;
	adj.assign(N+1, vector<Node>());
	dist.assign(N+1, INF);

	int u, v, c;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
	}
	int start, destination;
	cin >> start >> destination;

	priority_queue<Node, vector<Node>, greater<Node>> pq;

	pq.push({0, start});
	dist[start] = 0;
	while(!pq.empty()) {
		auto [ccost, cur] = pq.top();
		pq.pop();
		if (dist[cur] < ccost) continue;
		for (auto [ncost, nxt] : adj[cur]) {
			if (dist[nxt] > dist[cur] + ncost){
				dist[nxt] = dist[cur] + ncost;
				pq.push({dist[nxt], nxt});
			}
		}
	}
	cout << dist[destination];
	return 0;
}