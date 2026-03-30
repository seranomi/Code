/*
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void queen(int r, int c){
	board[r][c] += 1;
	for (int i = 0; i < 8; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		while(0 <= nr && nr < N && 0 <= nc && nc < N){
			board[nr][nc] += 1;
			nr += dr[i];
			nc += dc[i];
		}
	}
}

void move(int r, int c){
	if (board[r][c])
	
	for (int i = 0; i < N; i++){
		move(r + 1, i);
	}
}

int main(){
	cin >> N;
	board.assign(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++){
		move(0, i);
	}
	
}
*/
/*
N-Queen

N개의 칸 선택
겹치는게 없으면 카운트
N < 15 라 14C14^2 을 하기 너무 어려움

1개씩 겹치지 않게 놓기
N개 놓으면 카운트
뒤로 가는게 어렵다

한 행씩만 확인해도 가능
대각 특징
/ 우상 좌하 대각
row + col 값이 같다
배열에 0 ~ 2N 대각 정보로 입력 가능

\ 좌상 우하 대각
row - col 값이 같다
0-(N-1) 의 경우 음수 배열이라 보정 + (N-1)
*/

#include <iostream>
// #include <vector>

using namespace std;

int N;
int cnt = 0;
bool column[15] = {false};
bool diag1[30] = {false}; // 우상 좌하
bool diag2[30] = {false}; // 좌상 우하
// vector<vector<int>> res; 
// vector<int> temp;

void move(int r){
	if (r == N) {
		// res.push_back(temp);
		cnt++;
		return;
	}
	for (int c = 0; c < N; c++){
		if (column[c]) continue;
		if (diag1[r + c]) continue;
		if (diag2[r - c + N - 1]) continue;
		column[c] = true;
		diag1[r + c] = true;
		diag2[r - c + N - 1] = true;
		// temp[r] = c;
		move(r + 1);
		column[c] = false;
		diag1[r + c] = false;
		diag2[r - c + N - 1] = false;
	}
}

int main(){
	cin >> N;
	// temp.assign(N, 0);
	move(0);
	cout << cnt << '\n';
	// for (auto i : res){
	// 	for (int c : i){
	// 		cout << c << ' ';
	// 	}
	// 	cout << '\n';
	// }
	return 0;
}