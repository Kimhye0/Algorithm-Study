#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int cache[15];
int T[15] = {-1,}; //���Ⱓ
int P[15] = {-1,}; //�ݾ�
int N;

//begin ���� �����ѳ��� ������ ���� : return P[begin]
int profit(int begin) { //0���ͽ���
	if (N < begin + T[begin]) return 0;
	else return P[begin];
}

//begin ���� �����ѳ��� �ִ� ������ ����
int memo(int begin) {
	//�����ִ� ������ڰ� N���� ũ�� ����
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