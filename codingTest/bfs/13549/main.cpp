#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;

int N, K;
vector<int> dist(MAX, MAX);
queue<pair<int, int>> q;

void bfs() {
	q.push({N, 0});
	dist[N] = 0;
	while(!q.empty()) {
		auto [cur, t] = q.front();
		q.pop();
		// x-1
		if (0 <= cur - 1 && t+1 < dist[cur - 1]){
			q.push({cur - 1, t + 1});
			dist[cur - 1] = t + 1;
		}
		// x+1
		if (cur + 1 < MAX && t+1 < dist[cur + 1]){
			q.push({cur + 1, t + 1});
			dist[cur + 1] = t + 1;
		}
		// x*2
		if (cur * 2 < MAX && t < dist[cur * 2]){
			q.push({cur * 2, t});
			dist[cur * 2] = t;
		}
	}
}

int main() {
	cin >> N >> K;
	bfs();
	cout << dist[K] << '\n';
	return 0;
}