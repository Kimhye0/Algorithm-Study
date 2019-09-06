#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//N : ������ ����
//B : �Ѱ������� �ѹ濡�� �����Ҽ��ִ� �����ڼ�
//C : �ΰ������� �ѹ濡�� �����Ҽ��ִ� �����ڼ�
int N, B, C;
const int MAX = 1000000;
int A[MAX];

//�Ѱ������� �ѹ濡 ���� 1��. �ΰ������� ������ ����
//�ʿ��� ���������� �ּҰ� ���ϱ�
long long solve() {
	
	long long res = 0;

	//1.�Ѱ����� ���� ��ġ -> ������ �ΰ�����
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