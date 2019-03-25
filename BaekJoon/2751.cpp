#include <iostream>
#include <cstdio>

using namespace std;
int n;
int num[1000000];
int *num2;

void mergeSort(int left, int mid,int right) {
	int i, j,k;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (num[i] <= num[j])
			num2[k++] = num[i++];
		else
			num2[k++] = num[j++];

	}
	int tmp = i > mid ? j : i;
	while (k <= right) num2[k++] = num[tmp++];
	for (int i = left; i <= right; i++) {
		num[i] = num2[i];
	}
}

void partition(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		mergeSort(left, mid,right);
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	partition(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << num[i] <<endl;
	}
	return 0;
}