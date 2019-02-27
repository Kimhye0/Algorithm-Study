#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1000];

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	cout << dp[n] << endl;

	return 0;
}