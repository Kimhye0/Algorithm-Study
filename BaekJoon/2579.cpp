#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[301];
int score[301];

int main() {
	int input;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		cin >> score[i];
	}
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	
	for (int i = 3; i <= input; i++) {
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i-1]+score[i]);
	}
	cout << dp[input] << endl;

	return 0;
}