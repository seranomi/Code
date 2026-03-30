/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string out;
	int T, M, n;
	cin >> T;
	for (int i = 0; i < T; i++){
		vector<int> nums;
		cin >> M;
		out += to_string(M/2 + 1);
		for (int j = 0; j < M; j++){
			if (j % 20 == 0) out += '\n';
			cin >> n;
			nums.push_back(n);
			if (j % 2 == 0){
				sort(nums.begin(), nums.end());
				out += to_string(nums[j/2]);
				out += ' ';
			}
		}
		out += '\n';
	}
	cout << out;
	return 0;
}
*/

// 걍 정렬해서 중앙값 찾으면 되잖아!
// 우선순위큐를 어떻게 사용함!!

#include <iostream>
#include <queue>

using namespace std;

int main(){
	string out;
	int T, M, n;
	cin >> T;
	for (int i = 0; i < T; i++){
		priority_queue<int> max;
		priority_queue<int, vector<int>, greater<int>> min;
		cin >> M;
		out += to_string(M/2 + 1);
		for (int j = 0; j < M; j++){
			if (j % 20 == 0) out += '\n';
			cin >> n;
			if (max.empty() || max.top() >= n){
				max.push(n);
			}else {
				min.push(n);
			}
			if (j % 2 == 0){
				int gap = max.size() - min.size();
				if (gap > 1){
					min.push(max.top());
					max.pop();
				}if (gap < 1){
					max.push(min.top());
					min.pop();
				}
				out += to_string(max.top());
				out += ' ';
			}
		}
		out += '\n';
	}
	cout << out;
	return 0;
}

/*
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    string out;

    while (T--) {
        int M;
        cin >> M;

        priority_queue<int> leftPQ;
        priority_queue<int, vector<int>, greater<int>> rightPQ;

        out += to_string(M / 2 + 1) + '\n';

        int printed = 0;

        for (int i = 0; i < M; i++) {
            int x;
            cin >> x;

            if (leftPQ.empty() || x <= leftPQ.top()) {
                leftPQ.push(x);
            } else {
                rightPQ.push(x);
            }

            if ((int)leftPQ.size() > (int)rightPQ.size() + 1) {
                rightPQ.push(leftPQ.top());
                leftPQ.pop();
            } else if ((int)leftPQ.size() < (int)rightPQ.size()) {
                leftPQ.push(rightPQ.top());
                rightPQ.pop();
            }

            if (i % 2 == 0) {
                out += to_string(leftPQ.top()) + ' ';
                printed++;

                if (printed % 10 == 0) out += '\n';
            }
        }

        if (printed % 10 != 0) out += '\n';
    }

    cout << out;
    return 0;
}
*/