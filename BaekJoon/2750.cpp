#include <iostream>
#include <cstdio>
using namespace std;
int n;
int num[1000];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//첫번째값 pivot 설정.
void quickSort(int left, int right) {
	int i, j, pivot;
	if (left < right) {
		i = left + 1;
		j = right;
		pivot = num[left];
		do {
			while (num[i]<pivot) {
				i++;
			}
			while (num[j] > pivot) {
				j--;
			}
			if (i < j) {
				swap(num[i], num[j]);
			}
		} while (i<j);
		swap(num[left],num[j]);
		quickSort(left, j - 1);
		quickSort(j + 1, right);
	}
	
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&num[i]);
	}
	quickSort(0,n-1);
	for (int i = 0; i < n; i++) {
		cout << num[i] << endl;
	}
	return 0;
}