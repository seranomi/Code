#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, K;
	queue<int> q;
	int visited[150000] = {};
	cin >> N >> K;

	q.push(N);
	visited[N] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if (cur == K) break;
		int action[3] = {cur - 1, cur + 1, cur * 2};
		for (int nxt : action){
			if (nxt < 0 || 150000 <= nxt) continue;
			if (visited[nxt] == 0){
				q.push(nxt);
				visited[nxt] = visited[cur] + 1;
			}
		}
	}
	cout << visited[K] - 1;	
}