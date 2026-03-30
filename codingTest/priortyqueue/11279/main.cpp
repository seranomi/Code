#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib> // abs 정수

using namespace std;

int main(){
	vector<int> res;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 절댓값, 원래값
	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		int num;
		cin >> num;
		if(num == 0){
			if(pq.empty()) res.push_back(0);
			else{
				auto [abs, n] = pq.top();
				res.push_back(n);
				pq.pop();
			}
		}else{
			pq.push({abs(num), num});
		}
	}

	for (int n : res){
		cout << n << '\n';
	}

	return 0;
}