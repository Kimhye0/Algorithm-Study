#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int cnt = 1;

	cout << "<";

	while (!q.empty()) {
		if (cnt % M == 0) {
			result.push_back(q.front());
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}

	for (int i = 0; i < N-1; i++) {
		cout << result[i] << ", ";
	}

	cout << result[N-1] <<">";

	return 0;
}