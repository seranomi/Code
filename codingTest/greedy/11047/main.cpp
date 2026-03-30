#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	vector<int> coin(N);
	for (int i = 0; i < N; i++){
		cin >> coin[i];
	}
	int cnt = 0;
	int i = N - 1;
	// while (K > 0 && i >= 0){
	// 	if (coin[i] <= K){
	// 		K -= coin[i];
	// 		cnt++;
	// 	}else {
	// 		i--;
	// 	}
	// }
	for (int i = N - 1; i >= 0; i--){
		cnt += K / coin[i];
		K %= coin[i];
	}
	cout << cnt;
	return 0;
}