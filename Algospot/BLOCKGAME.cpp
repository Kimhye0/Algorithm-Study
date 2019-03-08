#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> moves;
char cache[1 << 25];
inline int cell(int y, int x) { return 1 << (y * 5 + x); }

void precalc() {
	//1.��ĭ¥�� ����� ��� ���
	for (int y = 0; y<4; ++y)
		for (int x = 0; x<4; ++x) {
			vector<int> cells;
			for (int dy = 0; dy < 2; ++dy)
				for (int dx = 0; dx < 2; ++dx)
					cells.push_back(cell(y + dy, x + dx));
			int square = cells[0] + cells[1] + cells[2] + cells[3];//���簢������
			//��ĭ�� ���� ���� ���
			for (int i = 0; i<4; ++i)
				moves.push_back(square - cells[i]);
		}
	//2.��ĭ¥�� ��� ��� : ���ΰ� ��ĭ�̸� ���ΰ� ��ĭ, ���ΰ� ��ĭ�̸� ���ΰ� ��ĭ
	for (int i = 0; i<5; ++i)
		for (int j = 0; j<4; ++j) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
}


//�������� board �϶� ���� ������ ����� �¸����� �Ǵ�
char play(int board) {

	char& ret = cache[board];
	if (ret != -1) return ret;

	ret = 0;
	//������Ǽ� moves�迭�� �� �˻�
	for (int i = 0; i<moves.size(); ++i)
		if ((moves[i] & board) == 0)//���� ���忡 ���������ʾҰ�
			if (!play(board | moves[i])) { //�����ǿ� ���� �� ���� ���
				ret = 1; //���������� ���� ����� �ڽ��̹Ƿ� �̱�
				break;
			}
	return ret;
}

int main() {
	int t; cin >> t;
	precalc();
	while (t--) {
		memset(cache, -1, sizeof(cache));
		//board �ʱ�ȭ
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


