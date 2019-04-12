#include <iostream>
#include <algorithm>

using namespace std;
int tree[64][64];

void solve(int row, int col, int size) {

	if (size == 1) {
		cout << tree[row][col];
		return;
	}
	bool zero = true, one = true;
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (tree[i][j])
				zero = false;
			else
				one = false;
		}
	}
	if (zero) cout << 0;
	else if (one) cout << 1;
	else {
		cout << "(";
		solve(row, col, size / 2); // 왼쪽위 - 2사분면
		solve(row, col + size / 2, size / 2); //오른쪽위 - 1사분면
		solve(row + size / 2, col, size / 2); //왼쪽아래 - 3사분면
		solve(row + size / 2, col + size / 2, size / 2); //오른쪽아래 - 4사분면
		cout << ")";
	}
	return;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d",&tree[i][j]);
		}
	}
	solve(0, 0, N);
	cout << "\n";

	return 0;
}