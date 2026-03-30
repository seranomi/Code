#include <iostream>
using namespace std;

int N, M;
int selected[8];

void dfs(int start, int depth){
	if (depth == M){
		for (int i = 0; i < M; i++){
			cout << selected[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= N; i++){
		selected[depth] = i;
		dfs(i, depth + 1);
	}
}
// 중복 조합

int main(){
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}