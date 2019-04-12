#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int R,C;

int dfs(vector<vector<int>> &picture,int x, int y, int val) {
	int cnt = 1;
	picture[x][y] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx>=0 && nx < R && ny>=0 && ny < C && picture[nx][ny]==val) {
			cnt += dfs(picture,nx, ny, val);
		}
	}
	return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	R = m;
	C = n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j]!=0) {
				int tmp = dfs(picture,i, j, picture[i][j]);
				number_of_area++;
				if (max_size_of_one_area < tmp) {
					max_size_of_one_area = tmp;
				}
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

//int main() {
//	int m;
//	int n;
//	cin >> m >> n;
//	vector<vector<int>> picture(m, vector<int>(n));
//	for (int i = 0; i < m; i++) {
//		int tmp;
//		for (int j = 0; j < n; j++) {
//			cin >> tmp;
//			picture[i][j] = tmp;
//		}
//	}
//	vector<int> answer(2);
//	answer = solution(m, n, picture);
//	cout << answer[0] << endl << answer[1] << endl;
//
//	return 0;
//}