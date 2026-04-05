#include <iostream>
using namespace std;

long long powerMod(long long a, long long b, long long c){
	a %= c;
	if (b == 0) return 1;
	if (b == 1) return a;
	// 깊이 줄이기 -> 중복 제거!!!!
	long long half = powerMod(a, b/2, c);
	if (b % 2 == 0){ // b 짝수
		return (half * half) % c;
	} else {
		return ((half * half) % c * a) % c;
	}
}

int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	cout << powerMod(A, B, C) << '\n';
	return 0;
}