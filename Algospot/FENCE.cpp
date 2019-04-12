#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

//h[left..right]�������� ���� ū �簢���� ���� ��ȯ.
//1.���ʺκ� ���� ū ���簢�� ����
//2.�����ʺκ� ���� ū ���簢�� ����
//3.�߰��� ��ģ ���� ū ���簢�� ����
//���߿� �ϳ��� ��.
int solve(vector<int>& h,int left, int right) {
	if (left == right) return h[left];
	int mid = left + right / 2;

	//[left..mid] , [mid+1..right] �� ����
	int ret = max(solve(h,left,mid), solve(h,mid+1,right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo],h[hi]);

	//[mid,mid+1]�� �ʺ�2�� ���簢��
	ret = max(ret, height*2);

	//�簢���� �Է���ü�� ���������� Ȯ��.
	while (left < lo || right > hi) {
		//���̰� �� ���������� Ȯ��.
		if (hi < right && (lo==left || (h[lo-1] < h[hi+1]))) {
			++hi;
			height = min(height,h[hi]);
		}
		else {
			--lo;
			height = min(height,h[lo]);
		}
		//Ȯ�� �� �簢�� ����
		ret = max(ret, height*(hi-lo+1));
	}
	return ret;
}

int main() {
	int C;
	int N;
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> h(N,0);
		for (int i = 0; i < N; i++) {
			scanf("%d", &h[i]);
		}
		cout << solve(h,0,N-1) <<"\n";
	}
	return 0;
}