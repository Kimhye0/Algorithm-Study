#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> moves;
char cache[1 << 25];
inline int cell(int y, int x) { return 1 << (y * 5 + x); }

void precalc() {
	//1.세칸짜리 ㄱ모양 블록 계산
	for (int y = 0; y<4; ++y)
		for (int x = 0; x<4; ++x) {
			vector<int> cells;
			for (int dy = 0; dy < 2; ++dy)
				for (int dx = 0; dx < 2; ++dx)
					cells.push_back(cell(y + dy, x + dx));
			int square = cells[0] + cells[1] + cells[2] + cells[3];//정사각형만들어서
			//한칸씩 빼면 ㄱ자 블록
			for (int i = 0; i<4; ++i)
				moves.push_back(square - cells[i]);
		}
	//2.두칸짜리 블록 계산 : 가로가 한칸이면 세로가 두칸, 가로가 두칸이면 세로가 한칸
	for (int i = 0; i<5; ++i)
		for (int j = 0; j<4; ++j) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
}


//게임판이 board 일때 현재 차례인 사람이 승리할지 판단
char play(int board) {

	char& ret = cache[board];
	if (ret != -1) return ret;

	ret = 0;
	//모든경우의수 moves배열로 다 검사
	for (int i = 0; i<moves.size(); ++i)
		if ((moves[i] & board) == 0)//아직 보드에 놓여지지않았고
			if (!play(board | moves[i])) { //게임판에 놓을 수 없는 경우
				ret = 1; //마지막으로 놓은 사람이 자신이므로 이김
				break;
			}
	return ret;
}

int main() {
	int t; cin >> t;
	precalc();
	while (t--) {
		memset(cache, -1, sizeof(cache));
		//board 초기화
		int board = 0;
		for (int y = 0; y < 5; ++y)
			for (int x = 0; x < 5; ++x) {
				char c; cin >> c;
				if (c == '#') board += cell(y, x);
			}
		if (play(board)) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;
	}

	return 0;
}


