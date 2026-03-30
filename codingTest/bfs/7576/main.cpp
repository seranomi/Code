#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int	main(){
	int N, M;
	vector<vector<int>> dist;
	queue<pair<int, int>> q;
	
	int dr[4] = {-1, 1, 0, 0}; 
	int dc[4] = {0, 0, -1, 1};
	cin >> M >> N;
	dist.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> dist[i][j];
			if (dist[i][j] == 1){
				q.push({i, j});
			}
		}
	}
	while(!q.empty()){
		auto [r, c] = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
			if (dist[nr][nc] == 0){
				q.push({nr, nc});
				dist[nr][nc] = dist[r][c] + 1;
			}
		}
	}
	int max = -1;
	int flag = false;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (max < dist[i][j]) max = dist[i][j];
			if (dist[i][j] == 0) flag = true;
		}
	}
	if (flag){
		cout << -1;
	}else{
		cout << max -1;
	}
}
