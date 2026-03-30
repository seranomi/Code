/*
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N;
vector<string> grid;
set<pair<int, int>> visited;
vector<int> ans(1, 0);


vector<pair<int, int>> actions(pair<int, int> cur){
	vector<pair<int, int>> nxts;
	
	if (0 <= cur.first - 1){ // 상
		nxts.push_back({cur.first-1, cur.second});
	}
	if (cur.first + 1 < N){ // 하
		nxts.push_back({cur.first+1, cur.second});
	}
	if (0 <= cur.second - 1){ // 좌
		nxts.push_back({cur.first, cur.second-1});
	}
	if (cur.second + 1 < N){ // 우
		nxts.push_back({cur.first, cur.second+1});
	}
	
	return nxts;
}

void dfs(pair<int, int> cur){
	visited.insert(cur);
	*ans.rbegin() += 1;
	for (pair<int, int> nxt : actions(cur)){
		if(!visited.count(nxt) && grid[nxt.first][nxt.second] == '1') dfs(nxt);
	}
}

int main(){
	cin >> N;	
	string str;
	for (int i = 0; i < N; i++){
		cin >> str;
		grid.push_back(str);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if(grid[i][j] == '1' && !visited.count({i, j})){
				ans[0] += 1;
				ans.push_back(0);
				dfs({i, j});
			}
		}
	}
	sort(ans.begin() + 1, ans.end()); //ans[0]은 단지 개수 나머지는 오르차순 정렬
	for(int n : ans){
		cout << n << '\n';
	}
	return 0;
}
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y){
	visited[x][y] = true;
	int cnt = 1;

	for(int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (!visited[nx][ny] && grid[nx][ny] == '1'){
			cnt += dfs(nx, ny);
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	visited.assign(N, vector<bool>(N, false));
	
	string str;
	for (int i = 0; i < N; i++){
		cin >> str;
		grid.push_back(str);
	}

	vector<int> complexes;

	for (int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (grid[i][j] == '1' && !visited[i][j]){
				complexes.push_back(dfs(i, j));
			}
		}
	}
	cout << complexes.size() << '\n';
	sort(complexes.begin(), complexes.end()); //
	for (int n : complexes){
		cout << n << '\n';
	}

	return 0;
}