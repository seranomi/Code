#include <iostream>
#include <vector>
#include <stack>
#include <queue>

const int kNodeNum = 9;
using namespace std;

bool visited[kNodeNum] = {false};
vector<int> graph[kNodeNum]; // 고정 노드
// 노드개수 입력 받을시
// vector<vector<int>> graph(n+1)
// vector<int> visited(n+1, false);

// 재귀
void dfs(int node) {
	visited[node] = true;
	cout << node << " ";
	for (int next_node : graph[node]){
		if (!visited[next_node]){
			dfs(next_node);
		}
	}
}

// 스택
void dfs_stack(int start_node) {
	stack<int> st;
	st.push(start_node);

	while (!st.empty()){
		int node = st.top();
		st.pop();

		if (visited[node]) continue;

		visited[node] = true;
		cout << node << " ";

		//스택에는 큰수부터 집어넣어
		//작은수 노드부터 탐색하도록 함
		for (int i = graph[node].size() - 1; i >= 0; i--){ 
			int next_node = graph[node][i];
			if (!visited[next_node]) st.push(next_node);
		}
		
	}
	cout << endl;
}

void bfs(int start_node){
	queue<int> q;
	q.push(start_node);
	visited[start_node] = true;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		cout << node << " ";

		for (int next_node : graph[node]){
			if(!visited[next_node]) {
				q.push(next_node);
				visited[next_node] = true;
			}
		}
	}
	cout << endl;
}

void bfs1(int root){
	queue<int> q;
	q.push(root);
	visited[root] = true;
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for(int nxt : graph[cur]){
			if(!visited[nxt]){
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
}

void init_graph(){
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	graph[2].push_back(1);
	graph[2].push_back(7);

	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	graph[4].push_back(3);
	graph[4].push_back(5);

	graph[5].push_back(3);
	graph[5].push_back(4);

	graph[6].push_back(7);

	graph[7].push_back(2);
	graph[7].push_back(6);

	graph[8].push_back(1);
	graph[8].push_back(7);
}

void refresh_visited(){
	for (int i = 0; i < kNodeNum; i++){
		visited[i] = false;
	}
}

int main(){
	init_graph();
	
	dfs_stack(8);
	refresh_visited();
	
	bfs1(8);
	
	return 0;
}

