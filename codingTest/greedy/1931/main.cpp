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
	int cnt = 1;
	int end = meeting[0].first;
	for (int i = 1; i < N; i++){
		if (end <= meeting[i].second){
			end = meeting[i].first;
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}