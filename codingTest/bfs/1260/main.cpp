#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int root){
	stack<int> st;
	st.push(root);
	
	while(!st.empty()){
		int cur = st.top();
		st.pop();
		
		if (visited[cur]) continue;
		
		visited[cur] = true;
		cout << cur << ' ';
		for (int i = adj[cur].size() - 1; i >= 0; i--){
			int nxt = adj[cur][i];
			if(!visited[nxt]){
				st.push(nxt);
			}
		}
	}
	cout << '\n';
}

void dfs_prob(int root){
	stack<int> st;
	st.push(root);
	
	while(!st.empty()){
		int cur = st.top();
		st.pop();
		visited[cur] = true;
		cout << cur << ' ';
		for (int i = adj[cur].size() - 1; i >= 0; i--){
			int nxt = adj[cur][i];
			if(!visited[nxt]){
				st.push(nxt);
			}
		}
	}
	cout << '\n';
}

void dfs_diff(int root){
	stack<int> st;
	st.push(root);
	visited[root] = true;
	
	
	while(!st.empty()){
		int cur = st.top();
		st.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]){
			if(!visited[nxt]){
				st.push(nxt);
				visited[nxt] = true;
			}
		}
	}
	cout << '\n';
}

void dfs_rec(int root){
	visited[root] = true;
	cout << root << ' ';
	for (int nxt : adj[root]){
		if(!visited[nxt]) dfs_rec(nxt);
	}
}

void bfs(int root){
	queue<int> q;
	q.push(root);
	visited[root] = true;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]){
			if(!visited[nxt]){
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
	cout << '\n';
}

int main() {
	cin >> N >> M >> V;

	adj.assign(N + 1, vector<int>(0));
	visited.assign(N + 1, false);

	int u, v;
	for (int i = 0; i < M; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++){
		sort(adj[i].begin(), adj[i].end());
	}

	bfs(V);
	fill(visited.begin(), visited.end(), false);
	dfs(V);
	fill(visited.begin(), visited.end(), false);
	dfs_prob(V);
	fill(visited.begin(), visited.end(), false);
	for (int i = 1; i <= N; i++){
		sort(adj[i].begin(), adj[i].end(), greater<int>());
	}
	dfs_diff(V);
	fill(visited.begin(), visited.end(), false);
	dfs_rec(V);
	cout << '\n';
	fill(visited.begin(), visited.end(), false);
	for (int i = 1; i <= N; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	dfs_rec(V);
	cout << '\n';
	return 0;

}
/*
5 5 1
1 4
1 2
2 3
2 4
3 4
*/