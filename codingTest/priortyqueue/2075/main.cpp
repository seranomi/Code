/*
#include <iostream>
#include <queue>
#include <vector>

// 제일 큰 놈 위에 수를 pq에 추가

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	priority_queue<pair<int,pair<int,int>>> pq;
	int N, num;
	cin >> N;
	vector<vector<int>> matrix(N, vector<int>(N));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> num;
			matrix[i][j] = num;
		}
	}
	
	for(int i = 0; i < N; i++){
		pair<int,pair<int,int>> cell = {matrix[N-1][i], {N-1, i}};
		pq.push(cell);
	}
	
	pair<int,pair<int,int>> max, up;
	for (int i = 0; i < N; i++) {
		max = pq.top();
		pq.pop();
		if (i == N - 1) break;
		auto [_, rc] = max;
		auto [row, col] = rc;
		up = {matrix[row-1][col], {row-1, col}};
		pq.push(up);
	}
	
	cout << max.first << '\n';
	
	return 0;
}
*/

// 메모리 빡빡쓰
// 음 정보가 입력 될때 동시에 처리가 가능 한가?
// N번째 큰 수만 필요하니 상위 N개만 저장하자!
// 그럼 최소힙을 사용해 제일 작은거를 처내서 N개 유지

#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, num;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++){
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < N*(N-1); i++){
		cin >> num;
		if (pq.top() < num){
			pq.pop();
			pq.push(num);
		}	
	}
	cout << pq.top();
	return 0;
}
