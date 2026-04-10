/*
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
const int INF = 1e9;
// 양수 찬스 있음 음수 찬스 없음

struct Miner {
	int x, y, chance;
};

int N, M;
vector<vector<bool>> board;
vector<vector<vector<int>>> dist;
// [r][c][chance] chance 0 없음, 1 있음

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs() {
	queue<Miner> q;
	dist[0][0][1] = 1;
	q.push({0, 0, 1});
	while (!q.empty()) {
		auto [r, c, chance] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
			if (dist[nr][nc][chance] != -1) continue;
			if (board[nr][nc]) {
				if (chance == 0) continue;
				q.push({nr, nc, 0}); // 찬스 사용
				dist[nr][nc][0] = dist[r][c][chance] + 1;
			}
			else {
				q.push({nr, nc});
				dist[nr][nc][chance] = dist[r][c][chance] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	board.assign(N, vector<bool>(M, false));
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '1') board[i][j] = true;
		}
	}
	dist.assign(N, vector<vector<int>>(M, vector<int>(2, -1)));
	bfs();
	int answer = dist[N-1][M-1][0] < dist[N-1][M-1][1] ? dist[N-1][M-1][0] : dist[N-1][M-1][1];
	cout << answer;
}
*/
// 모든 벽을 1번씩 부수고 bfs
// N=M=1,000 
// 거의 (NM)^2 이거는 시간이 너무 오래 걸린다.

// chance 유무 상태공간 추가
// dist가 작은게 우선 동일한 경우
/*
xy 좌표와 brake chance여부
b 1 있음 0 없음
상태공간 graph[r][c][b]
큐에는 좌표와 찬스가 여부가 들어감
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct State {
	int r, c, b;
};
int N, M;
vector<vector<vector<int>>> dist;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs() {
	queue<State> q;
	q.push({0, 0, true});
	dist[0][0][1] = 1;
	while(!q.empty()) {
		auto [r, c, b] = q.front();
		q.pop();
		//if (r == N-1 && c == M-1) break;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (dist[nr][nc][b] > 0) continue;
			if (dist[nr][nc][b] == -2) { // 벽
				if (b == 1 && dist[nr][nc][0] == -2) { // 찬스 있고 안 가본 벽이면 부수기
					q.push({nr, nc, 0});
					dist[nr][nc][0] = dist[r][c][b] + 1;
				}
				continue;
			}
			q.push({nr, nc, b}); // 길
			dist[nr][nc][b] = dist[r][c][b] + 1;
		}
	}
}

int main() {
	cin >> N >> M;
	dist.assign(N, vector<vector<int>>(M, vector(2, -2))); // 벽 -2
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '0') {
				dist[i][j][0] = -1; // 길 -1
				dist[i][j][1] = -1;
			}
		}
	}
	bfs();
	if (dist[N-1][M-1][0] != -1 && dist[N-1][M-1][1] != -1) {
		cout << min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
	} else {
		cout << max(dist[N-1][M-1][0], dist[N-1][M-1][1]);
	}
	return 0;
}