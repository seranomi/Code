#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> parent;

/*
bool dfs(int cur){
	visited[cur] = true;
	for (int nxt : adj[cur]){
		if(nxt == 1) return true;
		return dfs(nxt);
	}
	return false;
}

int parent(int node){
	visited[node] = true;
	for (int nxt : adj[node]){
		if (dfs(nxt)) return nxt;	
	}
}
*/
void dfs(int cur, int pre){
	parent[cur] = pre;
	for (int nxt : adj[cur]){
		if(parent[nxt] != 0) continue;
		dfs(nxt, cur);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> N;
	adj.assign(N + 1, vector<int>(0));
	
	int u, v;
	for (int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// 특정 지점의 부모 노드가 무엇인가?
	// for (int i = 2; i <= N; i++){
	// 	cout << parent(i) << '\n';
	// 	visited.assign(N + 1, false);
	// }
	// 문제 점 노드 찾기를 N^2수행 시간초과
	// 그냥 1번 노드 부터 내려가면서 기록

	parent.assign(N + 1, 0);
	dfs(1, -1);
	for (int i = 2; i <= N; i++){
		cout << parent[i] << '\n';
	}

	// 한쪽으로 길게 늘어진 트리일 경우
	// 재귀 스택 오버플로우 가능성 존재
	// 안전빵으로 bfs고려
}