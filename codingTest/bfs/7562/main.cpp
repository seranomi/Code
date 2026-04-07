#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int l;
int sr, sc;
int er, ec;
vector<vector<int>> visited;

// 나이트 이동
int dr[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dc[8] = {-1,  1, -2,  2, -2, 2, -1, 1};

int bfs() {
	queue<pii> q;
	q.push({sr, sc});
	visited[sr][sc] = 0;
	if (sr == er && sc == ec) return 0;
	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();
		int move = visited[r][c];
		for (int i = 0; i < 8; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || l <= nr || nc < 0 || l <= nc) continue;
			if (visited[nr][nc] != -1) continue;
			if (nr == er && nc == ec) return move + 1;
			q.push({nr, nc});
			visited[nr][nc] = move + 1;
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> l >> sr >> sc >> er >> ec;
		visited.assign(l, vector<int>(l, -1));
		cout << bfs() << '\n';
	}
	return 0;
}