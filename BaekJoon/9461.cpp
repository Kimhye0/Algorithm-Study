#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long cache[101];
int N;

//p(n):n개의 정삼각형이 있을때 가장 긴 변의 길이
long p(int n) {
	long& ret = cache[n];
	if (ret != -1) return ret;
	ret = p(n - 2) + p(n - 3);
	return ret;
}

int main() {
	int c;
	cin >> c;
	memset(cache,-1,sizeof(cache));
	cache[1] = cache[2] = cache[3] = 1;

	for (int i = 0; i < c; i++) {
		cin >> N;
		cout << p(N) << endl;
	}
	return 0;
}