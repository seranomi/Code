#include <iostream>
#include <vector>

using namespace std;
/*
4 * 3 * 3 * 3
*/

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<vector<int>> maxTet(N, vector<int>(M, 0));
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			int temp;
			for (int a = 0; a < 4; a++){
				int ar = i + dr[a];
				int ac = j + dc[a];
				if (ar < 0 || N <= ar || ac < 0 || M <= ac) continue;
				for (int b = 0; b < 4; b++){
					if (a == 0 && b == 1) continue;
					if (a == 1 && b == 0) continue;
					if (a == 2 && b == 3) continue;
					if (a == 3 && b == 2) continue;
					int br = ar + dr[b];
					int bc = ac + dc[b];
					if (br < 0 || N <= br || bc < 0 || M <= bc) continue;
					for (int c = 0; c < 4; c++){
						if (b == 0 && c == 1) continue;
						if (b == 1 && c == 0) continue;
						if (b == 2 && c == 3) continue;
						if (b == 3 && c == 2) continue;
						int cr = br + dr[c];
						int cc = bc + dc[c];
						if (cr < 0 || N <= cr || cc < 0 || M <= cc) continue;
						temp = board[i][j] + board[ar][ac] + board[br][bc] + board[cr][cc];
						if (maxTet[i][j] < temp) maxTet[i][j] = temp;
					}
				}	
			}
			for (int a = 0; a < 4; a++){// T자형 블럭 ㅜㅜ
				int ar = i + dr[a];
				int ac = j + dc[a];
				if (ar < 0 || N <= ar || ac < 0 || M <= ac) continue;
				for (int b = 0; b < 4; b++){
					if (a == 0 && b == 1) continue;
					if (a == 1 && b == 0) continue;
					if (a == 2 && b == 3) continue;
					if (a == 3 && b == 2) continue;
					int br = ar + dr[b];
					int bc = ac + dc[b];
					if (br < 0 || N <= br || bc < 0 || M <= bc) continue;
					for (int c = 0; c < 4 && b != c; c++){
						if (a == 0 && c == 1) continue;
						if (a == 1 && c == 0) continue;
						if (a == 2 && c == 3) continue;
						if (a == 3 && c == 2) continue;
						int cr = ar + dr[c];
						int cc = ac + dc[c];
						if (cr < 0 || N <= cr || cc < 0 || M <= cc) continue;
						temp = board[i][j] + board[ar][ac] + board[br][bc] + board[cr][cc];
						if (maxTet[i][j] < temp) maxTet[i][j] = temp;
					}
				}	
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (res < maxTet[i][j]) res = maxTet[i][j];
		}
	}
	cout << res;
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int ans = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c, int depth, int sum) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if (visited[nr][nc]) continue;

        visited[nr][nc] = true;
        dfs(nr, nc, depth + 1, sum + board[nr][nc]);
        visited[nr][nc] = false;
    }
}

void checkT(int r, int c) {
    int center = board[r][c];

    // 상하좌우 4방향 중 3개를 선택한 T 모양
    for (int skip = 0; skip < 4; skip++) {
        int sum = center;
        bool ok = true;

        for (int d = 0; d < 4; d++) {
            if (d == skip) continue;
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                ok = false;
                break;
            }
            sum += board[nr][nc];
        }

        if (ok) ans = max(ans, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;

            checkT(i, j);
        }
    }

    cout << ans << '\n';
    return 0;
}
*/