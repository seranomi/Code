#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> adjList;
vector<int> visited;
int order = 1;

void dfs(int cur){
	visited[cur] = order++;
	
	for(int nxt : adjList[cur]){
		if(!visited[nxt]){
			dfs(nxt);
		}
	}
}

int main(){
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
		sort(adjList[i].begin(), adjList[i].end(), greater<>());		
	}

	dfs(R);

	for (int i = 1; i <= N; i++){ // i번째줄에 i노드의 방문 순서 출력
		cout << visited[i] << '\n';
	}

	return 0;
}