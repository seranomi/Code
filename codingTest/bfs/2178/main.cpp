#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// struct node{
// 	int x, y, h;
// };

int N, M;
vector<string> maze;
// vector<vector<bool>> visited;
vector<vector<int>> dist;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = { 0, 0, -1, 1};

int bfs(){
	queue<pair<int, int>> q;
	q.push({0, 0});
	dist[0][0] = 1;

	while(!q.empty()){
		auto [r, c] = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
			if(maze[nr][nc] == '0' || dist[nr][nc] != 0) continue;
			q.push({nr, nc});
			dist[nr][nc] = dist[r][c] + 1;
		}
	}
	return dist[N-1][M-1];
}

int main(){
	cin >> N >> M;
	maze.assign(N, "");
	dist.assign(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++){
		cin >> maze[i];
	}
	cout << bfs() << '\n';
	return 0;
}