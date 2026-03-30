#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> time(N);
	for (int i = 0; i < N; i++){
		cin >> time[i];
	}
	sort(time.begin(), time.end());

	int sum = 0;
	for (int i = 0; i < N; i++){
		sum += (N - i) * time[i];
	}
	cout << sum;
	return 0;
}