#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int visit[100000];

int sumOfDigits(int A, int P) {
	int sum = 0;
	while (A != 0) {
		sum += (int)pow((A%10),P);
		cout << "sum" << sum << " ";
		A /= 10;
	}
	return sum;
}

void findRepetition(int A, int P) {
	visit[A]++;
	if (visit[A] > 2) return;
	findRepetition(sumOfDigits(A, P), P);
}

int main() {
	int A, P;
	int cnt = 0;
	cin >> A >> P;
	findRepetition(A, P);
	memset(visit, sizeof(visit), 0);
	
	for (int i = 0; i < 100000; i++) {
		if (visit[i] == 1) cnt++;
	}
	cout << cnt << endl;
	return 0;
}