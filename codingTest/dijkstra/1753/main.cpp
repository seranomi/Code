#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

int main() {
	int V, E, K;
	cin >> V >> E >> K;
	vector<vector<pii>> graph(V+1, vector<pii>());
	vector<int> dist(V+1, INF);
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, K});
	dist[K] = 0;

	while(!pq.empty()){
		auto [curCost, cur] = pq.top();
		pq.pop();
		if (curCost > dist[cur]) continue;
		for (auto [nxtCost, nxt] : graph[cur]){
			if(dist[nxt] > curCost + nxtCost){
				pq.push({curCost + nxtCost, nxt});
				dist[nxt] = curCost + nxtCost;
			}
		}
	}
	for (int i = 1; i <= V; i++){
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}