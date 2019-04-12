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

//ĳ��� ���� �뷮�� capacity�϶�, item ������ ���ǵ���
//��� ���� �� �ִ� �ִ� ���ڵ��� �� ��ȯ.
int pack(int capacity, int item) {
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	//�� ������ ���� ���� ���
	ret = pack(capacity, item+1);

	//�� ������ ���� ���
	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity-volume[item], item+1) + need[item]);
	}
	//���� ���� ����������� -> �� ū �� return.
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
	int capacity; //�뷮
	int cost; //���ڵ�
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