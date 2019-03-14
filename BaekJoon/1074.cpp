#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int N, r, c;
int cnt=0;

void solve(int size,int y,int x) {
	if (size == 2) {
		if (y == r && x == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (y == r && x+1 == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (y+1 == r && x == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		if (y + 1 == r && x + 1 == c) {
			cout << cnt << endl;
			return;
		}
		cnt++;
		return;//�ش� 2*2��Ͽ� r,c�� ���� ��� return.
	}
	//1��и�
	solve(size/2,y,x);
	//2��и�
	solve(size / 2, y,x+size/2);
	//3��и�
	solve(size/2,y+size/2,x);
	//4��и�
	solve(size / 2, y + size / 2, x+ size / 2);
}

int main(void) {
	cin >> N >> r >> c;
	solve(pow(2,N), 0, 0);
	return 0;
}