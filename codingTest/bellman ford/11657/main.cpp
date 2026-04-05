#include <iostream>
#include <vector>
using namespace std;
const int INF = (~0U);

using pii = pair<int, int>; // cost, node

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<pii>> graph(N+1, vector<pii>());
	vector<long long> dist(N+1, INF);

	int u, v, w;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}

	dist[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int u = 1; u <= N; u++) {
			for (auto [w, v] : graph[u]) {
				if (dist[u] != INF && dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
				}
			}
		}
	}
	for (int u = 1; u <= N; u++) {
		for (auto [w, v] : graph[u]) {
			if (dist[u] != INF && dist[v] > dist[u] + w){
				cout << -1; // 음수 사이클 존재
				return 0;
			}
		}
	}
	for (int i = 2; i <= N; i++){
		if (dist[i] == INF){
			cout << -1 << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
	return 0;
}
/*
간선 중심 사고인 벨만 포드 알고리즘
struct Edge{
	u, v, w
}; 로 풀기도 함
*/