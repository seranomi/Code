#include <iostream>
#include <vector>
#include <string>
using namespace std;
// N <=1024 N*N > 1,000,000
// M <= 100,000
int main() {
	int N, M, t;
	cin >> N >> M;
	vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){
			cin >> t;
			board[i][j] = t + board[i-1][j] + board[i][j-1] - board[i-1][j-1];
		}
	}
	int r1, c1, r2, c2;
	string str = "";
	// xx   xx -x_ +x ans
	// xt	__  x_
	for (int i = 0; i < M; i++){
		cin >> r1 >> c1 >> r2 >> c2;
		int sum = board[r2][c2] - board[r1-1][c2] - board[r2][c1-1] + board[r1-1][c1-1];
		str += to_string(sum) + '\n';
	}
	cout << str;
	return 0;
}