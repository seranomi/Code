#include <iostream>
#include <cmath>

int z(int r, int c, int N){
	if(N == 0) return 0;

	int half = 1 << (N-1);
	int quadrant = (r / half) * 2 + (c / half);

	return quadrant * half * half + z(r % half, c % half, N - 1);
}

int main(){
	int N, r, c;
	std::cin >> N >> r >> c;
	std::cout << z(r, c, N) << '\n';
	return 0;
}