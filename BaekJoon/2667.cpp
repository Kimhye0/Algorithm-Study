#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int map[30][30];
int group[30][30];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int ans[25*25];

void bfs(int x, int y, int cnt) {
	queue< pair<int, int> > q;
	q.push(make_pair(x,y));
	group[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny <n) {
				if (map[nx][ny] ==1 && group[nx][ny]==0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	
	scanf("%d", &n);
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d",&map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				bfs(i,j,++cnt);
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[group[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);

	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}