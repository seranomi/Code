#include <iostream>
using namespace std;

int N, M;

void dfs(int n, int level, int temp[]){
	if (level == M + 1) {
		for (int i = 1; i <= M; i++){
			cout << temp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = n; i <= N - M + level; i++){
		temp[level] = i;
		dfs(i + 1, level + 1, temp);
	}
}

int main(){
	cin >> N >> M;
	int temp[9] = {0};
	dfs(1, 1, temp);
}

/*
#include <iostream>
using namespace std;

int N, M;
int selected[8];

void dfs(int start, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= N - (M - depth) + 1; i++) {
        selected[depth] = i;
        dfs(i + 1, depth + 1);
    }
}

int main() {
    cin >> N >> M;
    dfs(1, 0);
}
*/