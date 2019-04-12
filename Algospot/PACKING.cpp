#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int volume[100], need[100];
int cache[1001][100];
string name[100];
int n;

//캐리어에 남은 용량이 capacity일때, item 이후의 물건들을
//담아 얻을 수 있는 최대 절박도의 합 반환.
int pack(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	//이 물건을 담지 않을 경우
	ret = pack(capacity, item+1);

	//이 물건을 담을 경우
	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity-volume[item], item+1) + need[item]);
	}
	//담을 경우와 담지않을경우 -> 더 큰 값 return.
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == n) return;
	if (pack(capacity, item) == pack(capacity, item +1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	int C;
	int capacity; //용량
	int cost; //절박도
	memset(cache,-1,sizeof(cache));

	cin >> C;
	
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &n, &capacity);
		vector<string> picked;
		for (int j = 0; j < n; j++) {
			cin >> name[j] >> volume[j] >> need[j];
		}
		reconstruct(capacity,0,picked);
		cout << pack(capacity, 0) <<" " << picked.size() <<"\n";
		for (int k = 0; k < picked.size(); k++) {
			cout << picked[k] << "\n";
		}
	}

	return 0;
}