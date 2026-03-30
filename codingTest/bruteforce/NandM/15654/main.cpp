#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
vector<int> selected;
vector<bool> visited;

void dfs(int depth){
	if (depth == M){
		for (int i = 0; i < M; i++){
			cout << selected[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++){
		if (visited[i]) continue;
		visited[i] = true;
		selected[depth] = num[i];
		dfs(depth + 1);
		visited[i] = false;
	}
}

int main(){
	cin >> N >> M;
	selected.assign(M, 0);
	num.assign(N, 0);
	visited.assign(N, false);
	for (int i = 0; i < N; i++){
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	dfs(0);
	return 0;	
}
