#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int num[8];
bool selected[8] = {false};
set<int> s;
int temp[8];

void dfs(int depth){
	ios::sync_with_stdio(false);
	if (depth == M){
		for (int i = 0; i < M; i++){
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int pre = -1; // 동일 깊이 이전에 사용한 값
	for (int i = 0; i < N; i++){
		if (selected[i]) continue;
		if (pre == num[i]) continue; // 이전 사용 값이랑 같으면 패스
		pre = num[i];
		temp[depth] = num[i];
		selected[i] = true;
		dfs(depth + 1);
		selected[i] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> num[i];
	}
	sort(num, num + N);

	dfs(0);

	return 0;

}
