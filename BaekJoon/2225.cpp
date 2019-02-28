#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long memo[201][201];
long long mod = 1000000000;
int N,K;

int main() {
	cin >> N >> K;
	memo[0][0] = 1LL;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= j; l++) {
				memo[i][j] += memo[i - 1][j - l];
				memo[i][j] %= mod;
			}
		}
	}
	cout << memo[K][N] << endl;

	return 0;
}