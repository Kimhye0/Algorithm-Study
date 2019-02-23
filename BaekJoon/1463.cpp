#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001];

int main() {
	d[1] = 0;
	int c;
	cin >> c;
	for (int i = 2; i <= c; i++) {
		d[i] = d[i - 1] + 1;
		if (i%3==0) {
			d[i] = min(d[i],d[i / 3] + 1);
		}
		if (i%2==0) {
			d[i] = min(d[i],d[i / 2] + 1);
		}
	}
	cout << d[c] << endl;
	return 0;
}
