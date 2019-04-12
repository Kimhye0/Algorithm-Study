#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[500][500];
int check[500][500];
int n, m;
int dx[] = {0,0,-1,1};
int dy[] = { 1,-1,0,0 };
int area[500*500];

void dfs(int x, int y, int cnt) {
	check[x][y] = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx>=0 && nx < n && ny >=0 && ny < m) {
			if (map[nx][ny]==1 && check[nx][ny]==0) {
				dfs(nx, ny, cnt);
			}
		}
	}

}

int main() {
	int cnt = 0;
	cin >> n >> m;
	//ют╥б
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//е╫╩Ж
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				dfs(i, j, ++cnt);
			}
		}
	}
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			area[check[i][j]] += 1;
		}
	}
	//sort(area+1, area + cnt + 1);
	cout << cnt << "\n";
	int max = area[1];
	for (int i = 1; i <= cnt; i++) {
		if (max < area[i]) {
			max = area[i];
		}
		
	}
	cout << max << "\n";
	return 0;
}