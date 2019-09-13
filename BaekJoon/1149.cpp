#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1001][3];
int d[1001][3] = { 0 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	//d[i] : i��° ������ ĥ������ ���� �ּҺ��, minimun[i] : i��° �� �ּҺ��
	//d[i] = d[i-1] + minimun[i]
	d[0][0] = cost[0][0];
	d[0][1] = cost[0][1];
	d[0][2] = cost[0][2];

	for (int i = 1; i < N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + cost[i][0]; //i��° ������ ĥ������ �ּҺ��. i��° ����ĥ��
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + cost[i][1]; //i��° ������ ĥ������ �ּҺ��. i��° �ʷ�ĥ��
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + cost[i][2]; //i��° ������ ĥ������ �ּҺ��. i��° �Ķ�ĥ��
	}

	cout << min(min(d[N-1][0],d[N-1][1]),d[N-1][2]) << "\n";

	return 0;
}