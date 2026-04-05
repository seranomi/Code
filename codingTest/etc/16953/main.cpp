/*
삽질
// int dfs(int n, int depth){ 
// if (n == b){ 
// return depth; 
// }else if (n > b){ 
// return -1; 
// } 
// 
//return max(dfs(2*n, depth + 1), dfs(10*n + 1, depth + 1)); // 4 5 경우 존재 
// int ans1 = dfs(2*n, depth + 1); 
// int ans2 = dfs(10*n + 1, depth + 1); 
// return (ans1 == -1 || ans2 == -1) ? max(ans1, ans2) : min(ans1, ans2); 
// } 
// 최소 깊이를 묻는 거라 dfs보다는 bfs가 좋아 보임 // 최단 -> bfs
*/

/*
#include <iostream>
#include <queue>
using namespace std;

long long a, b;

// 그냥하면 b가 1,000,000,000 일때 시간이 오래걸림
// * 10하면 int 범위 벗어나 무한 루프에 빠질 가능성 존재
int bfs(long long a){
	int res = -1;
	int depth = 1;
	queue<pair<long long, int>> q;
	q.push({a, depth});
	
	while(!q.empty()){
		auto [cur, depth] = q.front();
		q.pop();
		if (cur * 2 > b) continue;
		else if (cur * 2 == b){
			res = ++depth;
			break;
		}
		q.push({cur * 2, depth + 1});
		if (cur * 10 + 1 > b) continue;
		else if (cur * 10 + 1 == b){
			res = ++depth;
			break;
		}
		q.push({cur * 10 + 1, depth + 1});
	}
	return res;
}

int main(){
    cin >> a >> b;
	cout << bfs(a);
	
	return 0;
}
*/

/*
역순으로 가는 풀이
짝수면 나누기 2
1로 끝나면 1빼고 나누기 10
*/
#include <iostream>
using namespace std;

int main(){
	int a, cur;
	cin >> a >> cur;
	int depth = 1;
	while(cur > a){
		depth++;
		if (cur % 2 == 0){
			cur /= 2;
		}else if (cur % 10 == 1){
			cur /= 10;
		}else {
			depth = -1;
			break;
		}
	}
	if (cur < a) cout << -1;
	else cout << depth;
}