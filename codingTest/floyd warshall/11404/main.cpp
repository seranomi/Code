#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>; // weight, vertex

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int u, v, w;

	cin >> n >> m;

	vector<vector<pii>> graph(n+1, vector<pii>());
	vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		graph[u].push_back({w, v});
		if (dist[u][v] > w) dist[u][v] = w;
	}
	for (int i = 1; i <= n; i++){
		dist[i][i] = 0;
	}

	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (dist[i][j] == INF) cout << 0 << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}