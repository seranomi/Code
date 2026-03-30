#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct dfsGraph{
	int N, M, R;
	int cnt = 0; // 방문 순서
	vector<vector<int>> graph;
	vector<int> visited;
};

void init_graph(dfsGraph& g){
	cin >> g.N >> g.M >> g.R;
	g.graph = vector<vector<int>>(g.N + 1);
	g.visited = vector<int>(g.N + 1, 0);
	
	int v, w;
	for (int i = 0; i < g.M; i++){
		cin >> v >> w;
		g.graph[v].push_back(w);
		g.graph[w].push_back(v);
	}
	for (int i = 1; i <= g.N; i++){
		sort(g.graph[i].begin(), g.graph[i].end()); // 오름차순 정렬
	}
}

void dfs(int cur, dfsGraph& g){
	g.cnt++;
	g.visited[cur] = g.cnt;
	for (int nxt : g.graph[cur]){
		if (!g.visited[nxt]) dfs(nxt, g);
	}
}

void print_order(dfsGraph& g){
	for(int i = 1; i <= g.N; i++){
		cout << g.visited[i] << '\n'; // endl 줄바꿈 + flush(버퍼비우기) 이거바꾸니까 시간 확 줄어듦
	}
}
// i번째 줄에 i정점의 방문 순서를 적어야함
int main(){
	ios::sync_with_stdio(false); // printf동기화 끄기 cout cin만 사용
    cin.tie(nullptr); // cout과 cin의 묶음을 품 (출력 후에야 입력이 가능했지만 출력과 동시에 입력이 가능해진다)
	
	dfsGraph g;
	init_graph(g);
	dfs(g.R, g);
	print_order(g);
	return 0;
}

/*
// 전역변수 스타일
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
int cnt = 0;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int cur) {
    visited[cur] = ++cnt;
    for (int nxt : graph[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
		}
	}
}
			
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> R;
	graph.assign(N + 1, vector<int>()); //assign()함수 사용 가변길이 설정
	visited.assign(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;
		graph[v].push_back(w);
		graph[w].push_back(v);
	}
	
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
		
	dfs(R);
		
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << '\n';
	}
}
*/
// 문제 크기에 맞는 자료구조를 고르고, 필요한 만큼만 구조화