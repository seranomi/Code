#include <iostream>
#include <string>
#include <regex>

using namespace std;

// (100+1+|01)+
// 01, 1001, 0101, 10001, 10011
// 문자열 길이 200자 이내
/*
부분집합?

정규표현식
*/
// 정규표현식
bool sol(const string &str){
	regex e("(100+1+|01)+");
	return regex_match(str, e);
}

// 내 맘대로 풀이
bool sol2(string str){
	bool res = true;
	int i = 0;
	while(i < str.size()){
		if (str[i] == '0'){
			i++;
			if (str.size() <= i){
				res = false;
				break;
			}
			else{
				if (str[i] == '0'){
					res = false;
					break;
				}
				else{
					i++;
				}
			}
		}else {
			if (str.size() <= i + 2){
				res = false;
				break;
			}else{
				if (str[i+1] != '0' || str[i+2] != '0'){
					res = false;
					break;
				}
				else{
					i += 3;
					while (i < str.size() && str[i] == '0') i++;
					if (i >= str.size()){
						res = false;
						break;
					}
					while (i < str.size() && str[i] == '1'){
						if (i + 2 < str.size() && str[i+1] == '0' && str[i+2] == '0' && str[i-1] == '1'){
							break;
						}
						else if (i + 1 < str.size() && str[i+1] == '1'){
							i++;
						}
						else if (i + 1 < str.size() && str[i+1] == '0'){
							i++;
							break;
						}
						else if (i + 1 >= str.size()){
							i++;
							break;
						}
						else {
							res = false;
							break;
						}
					}
				}
			}
		}
	}
	return res;
}

int main(){
	int n;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> str;
		if(sol2(str)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}