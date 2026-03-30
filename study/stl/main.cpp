#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct coordinate
{
	int x;
	int y;
};

int main()
{
	coordinate xy  = {0, 0};
	vector<int> v;
	v = {1, 2, 3, 4};
	vector<int> v2(5);        // 크기 5, 값은 0
	vector<int> v3(5, 7);     // 크기 5, 모든 값 7
	sort(v.begin(), v.end(), greater<int>()); // 내림차순정렬
	vector<vector<coordinate>> board(5, vector<coordinate>(5, {0, 0}));

	v.push_back(5);
	cout << v.size() << endl;
	
	for (int i = board.size() - 1; 0 <= i; i--){
		for (int j = 0; j < v2.size(); j++){
			xy = {i, j};
			board[i][j] = xy;
			cout << board[i][j].y << board[i][j].x << " "; 
		}
		cout << endl;
	}
	cout << endl;

	string s = "hello";
	s[0] = 'H';
	s += " world";
	string sub = s.substr(3, 4); // 시작위치, 길이
	stringstream ss(s); // 공백기준 split
	string word;

	while(ss >> word){
		cout << word << endl;
	}
	cout << s << endl;
	cout << sub << endl;

	s = "apple,banana";

	ss.clear();
	ss.str(s);
	while(getline(ss, word, ',')){
		cout << word << endl;
	}

	s.replace(5, s.size(), "");
	cout << s << endl;

	return 0;
}