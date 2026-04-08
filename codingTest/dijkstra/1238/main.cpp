/*
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

vector<vector<int>> dist;
int N, M, X;

int main() {
	cin >> N >> M >> X;
	dist.assign(N+1, vector<int>(N+1, INF));
	for (int i = 0; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = w;
	}
	for (int i = 1; i < N+1; i++){
		dist[i][i] = 0;
	}
	for (int k = 1; k < N+1; k++){
		for (int i = 1; i < N+1; i++){
			for (int j = 1; j < N+1; j++){
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int max = 0;
	for (int i = 1; i < N+1; i++){
		if (max < dist[i][X] + dist[X][i]){
			max = dist[i][X] + dist[X][i];
		}
	}
	
	cout << max << '\n';
	return 0;
}
*/
// N 최대값 1000 플로이드 워셜은 O(N^3)
// 십억은 무리
// 다익스트라로 하나씩?
// X시작에서 전체 가는거 구하기 쉬움
// 다른거는 X나오면 조기 종료
/*
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

int N, M, X;
vector<vector<pii>> graph;

int main() {
	cin >> N >> M >> X;
	graph.assign(N+1, vector<pii>());
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({w, v}); // cost, node
	}
	
	// X에서 다른 노드까지의 거리 계산
	vector<int> distX(N+1, INF);
	distX[X] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, X});
	while (!pq.empty()) {
		auto [curCost, cur] = pq.top();
		pq.pop();
		if (curCost > distX[cur]) continue;
		for (auto [nxtCost, nxt] : graph[cur]) {
			if (distX[nxt] < nxtCost + curCost) continue;
			distX[nxt] = nxtCost + curCost;
			pq.push({distX[nxt], nxt});
		}
	}
	// 다른 노드에서 X 최단 경로 계산해서 distX에 더해주기
	for (int i = 1; i <= N; i++){
		vector<int> tempDist(N+1, INF);
		tempDist[i] = 0;
		priority_queue<pii, vector<pii>, greater<pii>> tempq;
		tempq.push({0, i});
		while (!tempq.empty()) {
			auto [curCost, cur] = tempq.top();
			tempq.pop();
			if (cur == X) {
				distX[i] += curCost;
				break;
			}
			if (curCost > tempDist[cur]) continue;
			for (auto [nxtCost, nxt] : graph[cur]) {
				if (tempDist[nxt] < nxtCost + curCost) continue;
				tempDist[nxt] = nxtCost + curCost;
				tempq.push({tempDist[nxt], nxt});
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < distX[i]) max = distX[i];
	}
	cout << max << '\n';
	return 0;
}
*/
/*
핵심은 파티장소 X에 있다.
다른 장소를 s라고 할때 
X -> s는 다익스트라로 쉽게 구할 수 있지만
s -> X는 바로는 구하기 어렵다.

하지만, 생각을 반대로 해보자 그래프를 그려서 생각해 보면
X에서 부터 역방향 그래프를 타고 가다보면 s에 도달할 수 있을 것이다.
이것이 1238문제 해결의 키이다.
*/
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// using pii = pair<int, int>;
// const int INF = 1e9;

// int main() {
// 	int N, M, X;
// 	cin >> N >> M >> X;
// 	vector<vector<int>> graph(N+1, vector<int>(N+1, INF));
// 	for (int i = 1; i <= N; i++){
// 		graph[i][i] = 0;
// 	}
// 	for (int i = 0; i < M; i++){
// 		int u, v, w;
// 		cin >> u >> v >> w;
// 		graph[u][v] = w;
// 	}
// 	// 순방향 X 다익스트라
// 	vector<int> distXtoS(N+1, INF);
// 	priority_queue<pii, vector<pii>, greater<pii>> pq;
// 	distXtoS[X] = 0;
// 	pq.push({0, X});
// 	while (!pq.empty()) {
// 		auto [curCost, cur] = pq.top();
// 		pq.pop();
// 		if (curCost > distXtoS[cur]) continue;
// 		for (int i = 1; i <= N; i++) {
// 			if (graph[cur][i] == INF) continue;
// 			if (distXtoS[i] > curCost + graph[cur][i]){
// 				distXtoS[i] = curCost + graph[cur][i];
// 				pq.push({distXtoS[i], i});
// 			}
// 		}
// 	}
// 	// 역방향 X 다익스트라
// 	// row, col 반대로 하면 역방향 그래프
// 	vector<int> distStoX(N+1, INF);
// 	distStoX[X] = 0;
// 	pq.push({0, X});
// 	while (!pq.empty()) {
// 		auto [curCost, cur] = pq.top();
// 		pq.pop();
// 		if (curCost > distStoX[cur]) continue;
// 		for (int i = 1; i <= N; i++) {
// 			if (graph[i][cur] == INF) continue;
// 			if (distStoX[i] > curCost + graph[i][cur]){
// 				distStoX[i] = curCost + graph[i][cur];
// 				pq.push({distStoX[i], i});
// 			}
// 		}
// 	}
// 	int max = 0;
// 	for (int i = 1; i <= N; i++){
// 		if (max < distXtoS[i] + distStoX[i]){
// 			max = distXtoS[i] + distStoX[i];
// 		}
// 	}
// 	cout << max << '\n';
// 	return 0;
// 	}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pii = pair<int, int>;
const int INF = 1e9;

vector<int> dijkstra(int start, const vector<vector<pii>>& graph) {
    int n = graph.size() - 1;
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [curCost, cur] = pq.top();
        pq.pop();

        if (curCost > dist[cur]) continue;

        for (auto [next, weight] : graph[cur]) {
            int nextCost = curCost + weight;
            if (dist[next] > nextCost) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pii>> graph(N + 1);
    vector<vector<pii>> reverseGraph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        reverseGraph[v].push_back({u, w});
    }

    vector<int> distFromX = dijkstra(X, graph);        // X -> i
    vector<int> distToX   = dijkstra(X, reverseGraph); // i -> X

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, distFromX[i] + distToX[i]);
    }

    cout << answer << '\n';
    return 0;
}
