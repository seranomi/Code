// 가로등
/*
N개의 가로등 가로등 위치 A1 ~ AN <=300 000
길의 위치 0 ~ L <= 10 ^ 18
어두운 정도 제일 작은 거 부터 K개 까지 출력

가로등 있는 것 기준으로 양옆을 bfs탐색하면 될듯?
map 위치-어두운 정도 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

long long L;
int N, K;
int k = 0;
vector<long long> light;
queue<long long> q;
map<long long, int> visited;

void sol(){
	for (int i = 0; i < N; i++){
		if(k < K){
			q.push(light[i]);
			visited[light[i]] = 0;
			cout << 0 << '\n';
			k++;
		}
		else return;
	}
	while (k < K){
		long long node = q.front();
		q.pop();
		
		long long left = node - 1;
		long long right = node + 1;
		
		if (0 <= left && !visited.count(left)){ // 왼쪽
			q.push(left);
			visited[left] = visited[node] + 1;
			cout << visited[left] << '\n';
			k++;
		}
		if (right <= L && !visited.count(right) && k < K){ // 오른쪽
			q.push(right);
			visited[right] = visited[node] + 1;
			cout << visited[right] << '\n';
			k++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	// 입력
	cin >> L >> N >> K;
	light.assign(N, 0);
	for (int i = 0; i < N; i++){
		cin >> light[i];
	}
	
	sol();
	
	return 0;
}

/*
방문은 배열 말고 set이나 해시 맵을 통해 구현 - L값이 매우 크기 때문
출력횟수 K값은 500 000으로 int형 범위 내이기 때문에 필요한 것만 출력하면 시간 절약 가능
O(K)
*/