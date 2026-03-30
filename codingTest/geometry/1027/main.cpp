/*
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 고층 건물

double slope(int x1, int y1, int x2, int y2){
	return (double)(y2 - y1) / (x2 - x1);
}

int main(){
	int N, n;
	vector<int> buildings;
	vector<vector<double>> slopes;
	// 굳이 2차원으로 저장할 필요없음 필요할때 계산하면 됨
	// 0으로 나누는 경우도 생김
	vector<int> cnt;
	cin >> N;
	slopes.assign(N, vector<double>(N));
	cnt.assign(N, 0);
	
	for (int i = 0; i < N; i++){
		cin >> n;
		buildings.push_back(n);
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			slopes[i][j] = slope(i, buildings[i], j, buildings[j]);
		}
		double min, max;
		int temp = 0;
		for (int j = i + 1; j < N; j++){
			if (j == i+1){
				min = max = slopes[i][j];
				temp = 1;
			}else {
				if (min >= slopes[i][j]) continue; // 과한 조건
				// temp에 추가되면 개수가 카운팅됨 기억을 한다는 소리
				else {
					if (max < slopes[i][j]){
						max = slopes[i][j];
						temp++;
					}
				}
			}
		}
		cnt[i] += temp;
		temp = 0;
		for (int j = i - 1; j >= 0; j--){
			if (j == i-1){
				min = max = slopes[i][j];
				temp = 1;
			}else {
				if (max <= slopes[i][j]) continue;
				else {
					if (min > slopes[i][j]){

						min = slopes[i][j];
						temp++;
					}
				}
			}
		}
		cnt[i] += temp;
	}

	int res = cnt[0];
	for (int x : cnt){
		if (res < x) res = x;
	}

	cout << res << '\n';

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double slope(int x1, int y1, int x2, int y2){
	return (double)(y2 - y1) / (x2 - x1);
}

int main() {
	int N;
	cin >> N;
	vector<int> buildings(N);
	for (int i = 0; i < N; i++){
		cin >> buildings[i];
	}

	int answer = 0;

	for (int i = 0; i < N; i++){
		int count = 0;
		
		double maxSlope = -numeric_limits<double>::max();
		for(int j = i+1; j < N; j++){
			double cur = slope(i, buildings[i], j, buildings[j]);
			if (maxSlope < cur){
				maxSlope = cur;
				count++;
			}
		}
		double minSlope = numeric_limits<double>::max();
		for(int j = i-1; j >= 0; j--){
			double cur = slope(i, buildings[i], j, buildings[j]);
			if (minSlope > cur){
				minSlope = cur;
				count++;
			}
		}
		if (answer < count) answer = count;
	}

	cout << answer << '\n';
	return 0;
}

/*
// 세 점 비교로 직접 판정
// 기울기 식에서 나눗셈을 제거해 double사용을 안 하는게 특징
// O(n^3)	
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int cnt = 0;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            bool visible = true;

            for (int k = min(i, j) + 1; k < max(i, j); k++) {
                long long left = (h[j] - h[i]) * (k - i);
                long long right = (h[k] - h[i]) * (j - i);

                if ((j - i > 0 && right >= left) || (j - i < 0 && right <= left)) {
                    visible = false;
                    break;
                }
            }

            if (visible) cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
*/