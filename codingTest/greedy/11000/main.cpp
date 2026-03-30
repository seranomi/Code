/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N, s, e;
	cin >> N;
	vector<pair<int, int>> meeting;
	for (int i = 0; i < N; i++){
		cin >> s >> e;
		meeting.push_back({e, s});
	}
	sort(meeting.begin(), meeting.end());
	int cnt = 0;
	while(N > 0){
		int end = 0;
		vector<bool> done(N, false);
		if (N == 1) {
			cnt++;
			break;
		}
		for (int i = 0; i < N; i++){
			if (end <= meeting[i].second){
				end = meeting[i].first;
				done[i] = true;
			}
		}
		for (int i = N-1; i >= 0; i--){
			if (done[i]) meeting.erase(meeting.begin() + i);
		}
		cnt++;
		N = meeting.size();
	}
	cout << cnt;
	return 0;
} // N < 200,000 시간초과남
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
	int N, s, e, t;
	cin >> N;
	vector<pair<int, int>> meeting;
	for (int i = 0; i < N; i++){
		cin >> t >> s >> e;
		meeting.push_back({s, e});
	}
	sort(meeting.begin(), meeting.end());
	
	// 배열에 저장 -> 시간 초과
	/*
	vector<int> end(1, 0);
	for(auto [s, e] : meeting){
		for(int i = 0; i < end.size(); i++){
			if(end[i] <= s){
				end[i] = e;
				break;
			} 
			if (i == end.size()-1){
				end.push_back(e);
				break;
			}
		}
	}
	cout << end.size();
	*/

	// 우선순위 큐 min heap사용
	priority_queue<int, vector<int>, greater<int>> pq;
	for(auto [s, e] : meeting){
		if (!pq.empty() && pq.top() <= s){
			pq.pop();
		}
		pq.push(e);
	}
	cout << pq.size();
}

