#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> score;
vector<vector<int>> dp;

int main() {
	int T, N;
	cin >> T;
	string output;
	while (T > 0){
		cin >> N;
		score.assign(2, vector<int>(N, 0));
		dp.assign(3, vector<int>(N, 0));
		
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < N; j++){
				cin >> score[i][j];
			}
		}

		// 0 위 선택
		// 1 아래 선택
		// 2 선택 안함
		dp[0][0] = score[0][0];
		dp[1][0] = score[1][0];
		for (int i = 1; i < N; i++){
			dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + score[0][i];
			dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + score[1][i];
			dp[2][i] = max(dp[0][i-1], dp[1][i-1]);
		}
		int maxSum;
		maxSum = max(dp[0][N-1], dp[1][N-1]);
		output += to_string(maxSum) + '\n';
		T--;
		
	}
	cout << output;
	return 0;
}
// 2
// 5
// 50 10 100 20 40
// 30 50 70 10 60
// 7
// 10 30 10 50 100 20 40
// 20 40 30 50 60 20 80

/*
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int maxSum;
int tempSum;

void back(int N) { // 너무 느림!
for(int i = 0; i < 2; i++){
	for(int j = 0; j < N; j++){
		if (selected[i][j] != 0) continue;
		tempSum += score[i][j];
		selected[i][j]++;
		for (int k = 0; k < 4; k++){
			int nr = i + dr[k];
			int nc = j + dc[k];
			if (nr < 0 || 2 <= nr || nc < 0 || N <= nc) continue;
			selected[nr][nc]++;
		}
		if (maxSum < tempSum) maxSum = tempSum;
		back(N);
		tempSum -= score[i][j];
		selected[i][j]--;
		for (int k = 0; k < 4; k++){
			int nr = i + dr[k];
			int nc = j + dc[k];
			if (nr < 0 || 2 <= nr || nc < 0 || N <= nc) continue;
			selected[nr][nc]--;
		}
	}
}
}
*/