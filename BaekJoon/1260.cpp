#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> A[1001];
bool check[1001];

//dfs : stack 구현
void dfs(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i < A[x].size(); i++) {
		int next = A[x][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

//bfs : queue 구현
void bfs(int x) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[x] = true;
	q.push(x);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node <<" ";
		for (int i = 0; i < A[node].size(); i++) {
			int next = A[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int N, M, start;
	cin >> N >> M >> start;//정점,간선,시작노드
	while (M--) {
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(A[i].begin(), A[i].end());
	}
	dfs(start);
	cout << endl;
	bfs(start);
	cout << endl;
	return 0;
}