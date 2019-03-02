#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
int n;

int main() {
	int cnt = 0;
	cin >> n;
	vector< pair<int, int> > cord(n);
	for (int i = 0; i < n; i++) {
		cin >> cord[i].first >> cord[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (cord[i].first == cord[j].first) {
				cnt++;
			}
			if (cord[i].second == cord[j].second) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}