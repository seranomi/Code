#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<int>> dist;
queue<pair<int, int>> q;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(){
	while(!q.empty()){
		auto [r, c] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || n <= nr || nc < 0 || m <= nc) continue;
			if (dist[nr][nc] == 0 && maze[nr][nc] == 1){
				q.push({nr, nc});
				dist[nr][nc] = dist[r][c] + 1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	maze.assign(n, vector<int>(m));
	dist.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> maze[i][j];
			if (maze[i][j] == 2) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}
	bfs();
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (maze[i][j] == 1 && dist[i][j] == 0){
				dist[i][j] = -1;
			}
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
