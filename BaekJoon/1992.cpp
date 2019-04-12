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
		solve(row, col, size / 2); // ������ - 2��и�
		solve(row, col + size / 2, size / 2); //�������� - 1��и�
		solve(row + size / 2, col, size / 2); //���ʾƷ� - 3��и�
		solve(row + size / 2, col + size / 2, size / 2); //�����ʾƷ� - 4��и�
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