#include <iostream>
#include <algorithm>
using namespace std;
#define CLOCK 16
#define ROW 5

void push_switch(int n, int cnt);
//bool check_all12hours(int *arr);

int clock[16];
int ans;
//열개의 스위치, 어떤시계랑 연결되었는지  표시.
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
스위치 한번 누를때마다 3시간 증가
4번 스위치 누르면 다시 제자리로 옴. 각각의 스위치는 0~3번만 누르면됨.
*/

//n:현재 스위치 번호. n=10이면 모든시계가 12시를 가르키는지 확인.
//cnt:지금까지 스위치누른 횟수.
void push_switch(int n, int cnt) {
	bool finished = true;
	for (int i = 0; i < CLOCK; i++) {
		if (clock[i] %12 !=0) {
			finished = false;
			break;
		}
	}
	//1.모두 12시일때 종료
	if (finished) {
		ans = min(ans, cnt);
		return;
	}
	//2.최소값 초과일때 종료
	if (ans <= cnt) {
		return;
	}
	//3.아직 모든시계가 12시로 셋팅안됨. 10번째 스위치까지 다 누른경우 종료.
	if (!finished && n == 10) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < ROW; j++) {
			if (switch_state[n][j] != -1) {
				clock[switch_state[n][j]] += 3 * i;
			}
		}
		//다음번 스위치로넘어감. 누른횟수도 넘겨줌.
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