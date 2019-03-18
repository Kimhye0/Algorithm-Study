#include <iostream>
#include <algorithm>

using namespace std;

int d[15][15];

int main() {
	int T,k,n;
	for (int i = 1; i <= 14; i++) {
		d[0][i] = i;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1];
		}
	}
	cin >> T;
	while (T--) {
		cin >> k;
		cin >> n;
		cout << d[k][n] << endl;
	}

	return 0;
}