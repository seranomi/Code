// 리프랑 리프사이 거리 비교해서 최대값반환
// 리프에서 다익스트라 2n(logn)^2
// 트리면 굳이 다익해야하나? BFS나 DFS로 그냥 가중치만 잘 더해주면 되는거 아닌가?
// 일단 킵고잉
/*
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

int n;
vector<vector<pii>> graph;
vector<bool> leaf;
vector<int> dist;

int dijkstraMax(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n+1, INF);
	int answer = 0;
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		auto [curCost, cur] = pq.top();
		pq.pop();
		//if (curCost > dist[start][cur]) continue;
		for (auto [nxt, nxtCost] : graph[cur]) {
			if (dist[nxt] > curCost + nxtCost) {
				dist[nxt] = curCost + nxtCost;
				pq.push({dist[nxt], nxt});
				if (answer < dist[nxt]) answer = dist[nxt];
			}
		}
	}
	return answer;
}

void dfs(int cur, int cost, vector<int> &dist) {
	dist[cur] = cost;
	for (auto [nxt, nxtCost] : graph[cur]) {
		if (dist[nxt] != -1) continue;
		dfs(nxt, cost + nxtCost, dist);
	}
}

int main() {
	cin >> n;
	// 그래프 초기화
	graph.assign(n+1, vector<pii>());
	int u, v, w;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	// 리프노드 확인
	leaf.assign(n+1, false);
	for (int i = 1; i <= n; i++) {
		if(graph[i].size() == 1) leaf[i] = true;
	}
	// 리프노드에 대해서 dfs
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> dist(n+1, -1);
		if (leaf[i]) {
			dfs(i, 0, dist);
			for (int j = 1; j <= n; j++) {
				if (answer < dist[j]) answer = dist[j];
			}
		}
	}
	cout << answer << '\n';
	return 0;
}

*/

// 메모리가 초과났는데요
// n 10,,000 2차원배열 400MB 제한은 128MB
// 개별 다익스트라 dist로 해결

// 이번에는 시간초과
// 리프중에 두개 골라 거리계산 -> 공통 부모로 부터의 거리합?
// 구현이 힘들다
// 트리 구조니까 다익까지는 굳이고 dfs로 해결

// 내 코드에서 과한 점은 모든 리프에 대해서 dfs를 한 부분이다.
// 한 노드에서 dfs시 가장 먼 노드는 트리 지름 중 하나이다.
// 가장 먼 노드에서 다시 가장 먼 노드로 가면 트리 지름이 되겠다.
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int n;
vector<vector<pii>> graph;
vector<int> dist;

void dfs(int cur, int cost){
	dist[cur] = cost;
	for (auto [nxt, nxtCost] : graph[cur]) {
		if (dist[nxt] != -1) continue;
		dfs(nxt, nxtCost + cost);
	}
}

int main() {
	cin >> n;
	int u, v, w;
	graph.assign(n+1, vector<pii>());
	dist.assign(n+1, -1);
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	dfs(1, 0);
	int r1Index, answer = -1;
	for (int i = 1; i <= n; i++) {
		if (answer < dist[i]){
			answer = dist[i];
			r1Index = i;
		}
	}
	dist.assign(n+1, -1);
	answer = -1;
	dfs(r1Index, 0);
	for (int i = 1; i <= n; i++) {
		if (answer < dist[i]){
			answer = dist[i];
		}
	}
	cout << answer;
	return 0;
}