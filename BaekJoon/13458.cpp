#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//N : 시험장 갯수
//B : 총감독관이 한방에서 감시할수있는 응시자수
//C : 부감독관이 한방에서 감시할수있는 응시자수
int N, B, C;
const int MAX = 1000000;
int A[MAX];

//총감독관은 한방에 오직 1명. 부감독관은 여러명 가능
//필요한 감독관수의 최소값 구하기
long long solve() {
	
	long long res = 0;

	//1.총감독관 먼저 배치 -> 나머지 부감독관
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		res++;
		if (A[i] > 0) {
			res += (A[i] % C == 0) ? (A[i]/C) : (A[i]/C+1);
		}	
	}
	return res;
}

int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> A[i];
	}
	cin >> B >> C;

	if (B<1 || B>MAX || C<1 || C>MAX) {
		exit(-1);
	}
	cout << solve() << "\n";

	return 0;
}