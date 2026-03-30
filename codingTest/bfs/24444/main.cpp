#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adjList;
vector<int> visited;
queue<int> q;
int order = 1;
int N, M, R;

void bfs(int root){
	q.push(root);
	visited[root] = order++;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for (int nxt : adjList[cur]){
			if(!visited[nxt]){
				q.push(nxt);
				visited[nxt] = order++;
			}
		}
	}
}

int main() {
	cin >> N >> M >> R;
	adjList.assign(N + 1, vector<int>(0));
	visited.assign(N + 1, 0);
	
	int u, v;
	for (int i = 0; i < M; i++){
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	for (int i = 1; i <= N; i++){
		sort(adjList[i].begin(), adjList[i].end());
	}

	bfs(R);

	for (int i = 1; i <= N; i++){
		cout << visited[i] << '\n';
	}

	return 0;
}

