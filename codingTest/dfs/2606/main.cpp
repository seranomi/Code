#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 연결되어있는 네트워크 개수가 궁금하기에
// set으로 방문여부 확인후 size반환
// 바이러스에 걸리게 되는 컴퓨터수
// 자기 자신 제외 size - 1 출력

vector<vector<int>> adj;
unordered_set<int> visited;
int N, E;

void dfs(int cur){
	visited.insert(cur);
	for(int nxt : adj[cur]){
		if(visited.find(nxt) == visited.end()){
			dfs(nxt);
		}
	}
}

int main() {
	cin >> N >> E;
	adj.assign(N + 1, vector<int>(0));

	int u, v;
	for(int i = 0; i < E; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << visited.size() - 1 << '\n';
	
}

