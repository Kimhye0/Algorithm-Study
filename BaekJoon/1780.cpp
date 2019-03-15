#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
short paper[2200][2200];
int ans[3] = { 0, };

//1.���̰� ��� ���� ���� �Ǿ��ִٸ� �״�� ���.
//2.(1)�� �ƴ� ��쿡�� ���̸� ���� ũ���� �� 9���� ���̷� �ڸ���, ������ ���̿� (1) ���� �ݺ�.
void solve(int row,int col, int size) {
	if (size == 1) {
		int num = paper[row][col] + 1;
		ans[num]++;
		return;
	}
	bool same = true;
	short first = paper[row][col];
	for (int y = row; y < row + size; y++) {
		if (!same) break;
		for (int x = col; x < col + size; x++) {
			if (first != paper[y][x]) {
				same = false;
				break;
			}
		}
	}
	if (same) {
		int num = paper[row][col] + 1;
		ans[num]++;
		return;
	}
	int newsize = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(row + newsize*i, col + newsize*j, newsize);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	solve(0, 0, N);

	cout << ans[0] << endl;
	cout << ans[1] << endl;
	cout << ans[2] << endl;

	return 0;
}