#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	int n, sum = 0;
	cin >> n;
	cin >> S;
	for (int i = 0; i < n; i++){
		sum += S[i] - '0'; // ascii코드 이용
	}
	cout << sum;
	return 0;
}

/*
         ,r'"7
r`-_   ,'  ,/
 \. ". L_r'
   `~\/
      |
      |
*/