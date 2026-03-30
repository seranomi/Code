#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, vector<vector<bool>>& matrix, vector<vector<bool>>& visited, int M, int N){
	visited[y][x] = true;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || M <= nx || ny < 0 || N <= ny ) continue;
		if(matrix[ny][nx] && !visited[ny][nx]){
			dfs(nx, ny, matrix, visited, M, N);
		}
	}

}

int main(){
	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int M, N, K;
		cin >> M >> N >> K;
		vector<vector<bool>> matrix(N, vector<bool>(M, false));
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		
		for(int j = 0; j < K; j++){
			int X, Y;
			cin >> X >> Y;
			matrix[Y][X] = true;
		}

		int res = 0;
		for(int n = 0; n < N; n++){
			for(int m = 0; m < M; m++){
				if (matrix[n][m] && !visited[n][m]){
					dfs(m, n, matrix, visited, M, N);
					res++;
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}