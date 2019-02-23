#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int cache[10000];
int INF = 987654321;
string N;

int classify(int a, int b) {
	string M = N.substr(a, b - a + 1);
	if (M == string(M.size(), M[0]))
		return 1;
	
	bool isProgress = true;
	for (int i = 0; i < M.size() - 1; i++) {
		if (M[i + 1] - M[i] != M[1] - M[0])
			isProgress = false;
	}
	if (isProgress && abs(M[1] - M[0]) == 1)
		return 2;

	bool isRotate = true;
	for (int i = 0; i < M.size(); i++) {
		if (M[i] != M[i % 2])
			isRotate = false;
	}
	if (isRotate) return 4;
	if (isProgress) return 5;
	
	return 10;
}

int memo(int begin) {
	//base case
	if (begin == N.size()) return 0;
	//memoization
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (int len = 3; len <= 5; len++) {
		if (begin + len <= N.size()) {
			ret = min(ret, memo(begin + len) + classify(begin, begin + len - 1));
		}
	}
	return ret;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		cout << memo(0) << endl;
	}

	return 0;
}
