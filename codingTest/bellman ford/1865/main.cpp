/*
한 지점에서 출발을 하여서 시간여행을 하기 시작하여 다시 출발을 하였던 위치로 돌아왔을 때, 
출발을 하였을 때보다 시간이 되돌아가 있는 경우가 있는지 없는지 궁금해졌다.

음수 사이클 여부 확인 후 출발
*/

#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
using pii = pair<int, int>;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, W;
		cin >> N >> M >> W;
		vector<vector<pii>> graph(N+1, vector<pii>());
		vector<long long> dist(N+1, 0);
		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({e, t});
			graph[e].push_back({s, t});
		}
		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			graph[s].push_back({e, -1 * t});
		}

		for (int i = 0; i < N-1; i++) {
			for (int s = 1; s <= N; s++) {
				for (auto [e, t] : graph[s]) {
					if (dist[s] != INF && dist[e] > dist[s] + t) {
						dist[e] = dist[s] + t;
					}
				}
			}
		}
		int count = 0;
		for (int s = 1; s <= N; s++) {
			for (auto [e, t] : graph[s]) {
				if (dist[s] != INF && dist[e] > dist[s] + t) {
					count++;
					break;
				}
			}
			if (count != 0) break;
		}
		if (count != 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}