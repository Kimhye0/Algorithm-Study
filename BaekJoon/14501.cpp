#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cache[15];
int T[15] = {-1,}; //상담기간
int P[15] = {-1,}; //금액
int N;

//begin 부터 시작한날의 상담수익 리턴 : return P[begin]
int profit(int begin) { //0부터시작
	if (N < begin + T[begin]) return 0;
	else return P[begin];
}

//begin 부터 시작한날의 최대 상담수익 리턴
int memo(int begin) {
	//남아있는 상담일자가 N보다 크면 종료
	if (begin > N-1) return 0;
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = -987654321;

	for (int i = begin; i < N; i++) {
		ret = max(ret , profit(i)+memo(T[i]+i));
	}
	return ret;
}

int main() {
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	cout << memo(0) << endl;

	return 0;
}