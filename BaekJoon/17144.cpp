#include <iostream>
#include <algorithm>

using namespace std;

int map[100][100];
int temparr[100][100] = { 0 };

int dx[] = {0,0,-1,1};
int dy[] = { 1,-1,0,0 };

int counterClockWiseY[] = {0,-1,0,1};
int counterClockWiseX[] = {1,0,-1,0};

int clockWiseY[] = { 0,1,0,-1 };
int clockWiseX[] = { 1,0,-1,0 };

int R, C, T;

void copymap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temparr[i][j] = map[i][j];
		}
	}
}

//확산은 동시에!!
//확산되는양, 확산되고 남은양 계산
void diffusion() {
	int copymap[100][100] = { 0 };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//미세먼지인 경우
			if (map[i][j] > 0) {
				int cnt = 0;
				int amount = map[i][j] / 5;

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx>=0 && nx < R && ny >=0 && ny <C && map[nx][ny] != -1) {
						cnt++;
						copymap[nx][ny] += amount;
					}
				}
				map[i][j] -= (amount*cnt);
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += copymap[i][j];
		}
	}

}
//위쪽 반시계방향
void counterclockwise(int start_y, int start_x) {
	//시작 좌표
	int y = start_y;
	int x = start_x + 1;
	map[y][x] = 0;

	for (int turn = 0; turn < 4; turn++) {
		while (1) {
			int ny = y + counterClockWiseY[turn];
			int nx = x + counterClockWiseX[turn];

			if (ny == start_y && nx == start_x) break;
			if (!(ny >= 0 && ny < R && nx >= 0 && nx < C)) break;

			map[ny][nx] = temparr[y][x];
			y = ny;
			x = nx;
		}
	}

}

//아래쪽 시계방향
//90도 턴할때마다 y좌표변화 Right:0 Down:1 Left:0 Up:-1
//90도 턴할때마다 x좌표변화 Right:1, Down:0, Left:-1, Up:0
void clockwise(int start_y, int start_x) {
	//시작 좌표
	int y = start_y;
	int x = start_x+1;
	map[y][x] = 0;

	for (int turn = 0; turn < 4; turn++) {
		while (1) {
			int ny = y + clockWiseY[turn];
			int nx = x + clockWiseX[turn]; 

			if (ny == start_y && nx == start_x) break;
			if (!(ny >= 0 && ny < R && nx >= 0 && nx < C)) break;

			map[ny][nx] = temparr[y][x];
			y = ny;
			x = nx;
		}
	}

}


int main() {

	cin.sync_with_stdio(false);

	int sum = 0;

	cin >> R >> C>> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

		}
	}

	for (int i = 0; i < T; i++) {
		diffusion();
		copymap();
		clockwise(3, 0);
		counterclockwise(2, 0);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			
			if (map[i][j] > 0) {
				sum += map[i][j];
			}
		}
		
	}
	cout << sum << "\n";

	return 0;
}