#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int N, kim, lim;

//Rk, Rk-1, Rk-2, ...,2, 1 : 1, 2, 2^2, ..., 2^k
int findRound(int n, int a, int b) {
	int cnt = 0;
	while (a != b) {
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		cnt++;
	}
	return cnt;
}

int main() {

	cin >> N >> kim >> lim;
	cout << findRound(N, kim, lim)<<endl;
	return 0;
}