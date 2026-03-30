#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
/*
입력 받을 때 예를 들어
ABC, BBB를 입력 받으면
map에 A 랑 A의 자리수 100을 넣어줌
map에 이미 존재하는 키 경우 값을 증가 시킴
A: 100
B: 121
C: 1
키값을 내림차순으로 정렬한 뒤
9부터 0까지 순서대로 곱해서 결과에 더해줌
*/

int exp(int n, int x){
	int res = 1;
	for (int i = 0; i < x; i++){
		res *= n;
	}
	return res;
}

int main(){
	int N;
	cin >> N;
	vector<string> words(N);
	map<char, int> mp;
	for (int i = 0; i < N; i++){
		cin >> words[i];
		int len = words[i].length();
		for (int j = 0; j < len; j++){
			char word = words[i][j];
			if (mp.count(word)) mp[word] += exp(10, len - j - 1);
			else mp[word] = exp(10, len - j - 1);
		}
	}
	
	vector<int> temp;
	for (auto it : mp){
		temp.push_back(it.second);
	}
	sort(temp.begin(), temp.end(), greater<int>());

	int res = 0;
	for (int i = 0; i < temp.size(); i++){
		res += temp[i] * (9 - i);
	}

	cout << res;
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> weight(26, 0);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int place = 1;
        for (int j = s.size() - 1; j >= 0; j--) {
            weight[s[j] - 'A'] += place;
            place *= 10;
        }
    }

    sort(weight.begin(), weight.end(), greater<int>());

    int num = 9;
    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (weight[i] == 0) break;
        ans += weight[i] * num;
        num--;
    }

    cout << ans << '\n';
    return 0;
}
*/