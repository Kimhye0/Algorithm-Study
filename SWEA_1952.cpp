#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int cost[4] = { 0 };
int plan[13] = { 0 };
int res;

void solve(int month, int sum) {
	if (month > 12) {
		if (res > sum) res = sum;
		return;
	}

	if (plan[month] == 0) {
		solve(month + 1, sum);
	}
	else {
		//1일 이용권
		solve(month + 1, sum + plan[month] * cost[0]);
		//한달 이용권
		solve(month + 1, sum + cost[1]);
		//3달 이용권
		solve(month + 3, sum + cost[2]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		for (int i = 0; i < 4; i++) {
			cin >> cost[i];
		}

		for (int month = 1; month < 13; month++) {
			cin >> plan[month];
		}
		res = cost[3];
		solve(1, 0);
		cout << "#" <<i <<" " << res << "\n";
	}


	return 0;
}