#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;
int n;

int main() {
	int cnt = 0;
	cin >> n;
	/*vector< pair<int, int> > cord(n);*/
	map<int, int> X, Y;
	for (int i = 0; i < n; i++) {
		/*cin >> cord[i].first >> cord[i].second;*/
		int x, y;
		cin >> x >> y;
		X[x]++;
		Y[y]++;
	}
	/*Time Complexity : O(n^)*/
	//for (int i = 0; i < n; i++) {
	//	for (int j = i+1; j < n; j++) {
	//		if (cord[i].first == cord[j].first) {
	//			cnt++;
	//		}
	//		if (cord[i].second == cord[j].second) {
	//			cnt++;
	//		}
	//	}
	//}

	/*Time Complexity : O(nlogn)*/
	for (map<int, int>::iterator it = X.begin(); it != X.end(); it++) {
		if (it->second >= 2) cnt++;
	}
	for (map<int, int>::iterator it = Y.begin(); it != Y.end(); it++) {
		if (it->second >= 2) cnt++;
	}
	cout << cnt << endl;
	return 0;
}