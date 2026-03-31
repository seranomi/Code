#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N, M;
int num[8];
int temp[8];

void dfs(int start, int depth){
	if (depth == M){
		for (int i = 0; i < M; i++){
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int pre = -1;
	for (int i = start; i < N; i++){
		if (pre == num[i]) continue;
		pre = num[i];
		temp[depth] = num[i];
		dfs(i, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> num[i];
	}
	sort(num, num + N);

	dfs(0, 0);

	return 0;

}
