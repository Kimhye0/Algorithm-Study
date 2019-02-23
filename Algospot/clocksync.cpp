#include <iostream>
#include <algorithm>
using namespace std;
#define CLOCK 16
#define ROW 5

void push_switch(int n, int cnt);
//bool check_all12hours(int *arr);

int clock[16];
int ans;
//������ ����ġ, ��ð�� ����Ǿ�����  ǥ��.
int switch_state[10][5] = {
	{ 0,1,2,-1,-1 },
	{ 3,7,9,11,-1 },
	{ 4,10,14,15,-1 },
	{ 0,4,5,6,7 },
	{ 6,7,8,10,12 },
	{ 0,2,14,15,-1 },
	{ 3,14,15,-1,-1 },
	{ 4,5,7,14,15 },
	{ 1,2,3,4,5 },
	{ 3,4,5,9,13 }
};

/*
����ġ �ѹ� ���������� 3�ð� ����
4�� ����ġ ������ �ٽ� ���ڸ��� ��. ������ ����ġ�� 0~3���� �������.
*/

//n:���� ����ġ ��ȣ. n=10�̸� ���ð谡 12�ø� ����Ű���� Ȯ��.
//cnt:���ݱ��� ����ġ���� Ƚ��.
void push_switch(int n, int cnt) {
	bool finished = true;
	for (int i = 0; i < CLOCK; i++) {
		if (clock[i] %12 !=0) {
			finished = false;
			break;
		}
	}
	//1.��� 12���϶� ����
	if (finished) {
		ans = min(ans, cnt);
		return;
	}
	//2.�ּҰ� �ʰ��϶� ����
	if (ans <= cnt) {
		return;
	}
	//3.���� ���ð谡 12�÷� ���þȵ�. 10��° ����ġ���� �� ������� ����.
	if (!finished && n == 10) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < ROW; j++) {
			if (switch_state[n][j] != -1) {
				clock[switch_state[n][j]] += 3 * i;
			}
		}
		//������ ����ġ�γѾ. ����Ƚ���� �Ѱ���.
		push_switch(n + 1, cnt + i);
		for (int j = 0; j < ROW; j++) {
			if (switch_state[n][j] != -1) {
				clock[switch_state[n][j]] -= 3 * i;
			}
		}
	}
	return;
}

//bool check_all12hours(int *arr) {
//	bool checktrue = true;
//	for (int i = 0; i < CLOCK; i++) {
//		if (arr[i] != 12) {
//			checktrue = false;
//			break;
//		}
//	}
//	return checktrue;
//}

int main() {
	
	int casenum;
	cin >> casenum;

	for (int i = 1; i <= casenum; i++) {
		ans = 999999999;
		for (int j = 0; j < CLOCK; j++) {
			cin >> clock[j];
		}
		push_switch(0, 0);
		if (ans == 999999999) ans = -1;
		cout << ans << endl;
	}

	return 0;
}