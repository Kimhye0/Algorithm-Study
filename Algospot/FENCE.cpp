#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

//h[left..right]구간에서 가장 큰 사각형의 넓이 반환.
//1.왼쪽부분 가장 큰 직사각형 넓이
//2.오른쪽부분 가장 큰 직사각형 넓이
//3.중간에 겹친 가장 큰 직사각형 넓이
//셋중에 하나가 답.
int solve(vector<int>& h,int left, int right) {
	if (left == right) return h[left];
	int mid = left + right / 2;

	//[left..mid] , [mid+1..right] 두 구간
	int ret = max(solve(h,left,mid), solve(h,mid+1,right));
	int lo = mid, hi = mid + 1;
	int height = min(h[lo],h[hi]);

	//[mid,mid+1]인 너비2인 직사각형
	ret = max(ret, height*2);

	//사각형이 입력전체를 덮을때까지 확장.
	while (left < lo || right > hi) {
		//높이가 더 높은쪽으로 확장.
		if (hi < right && (lo==left || (h[lo-1] < h[hi+1]))) {
			++hi;
			height = min(height,h[hi]);
		}
		else {
			--lo;
			height = min(height,h[lo]);
		}
		//확장 후 사각형 넓이
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