#include <iostream>
#include <algorithm>

using namespace std;

int findRule(int n) {
	int cnt = 0;
	int tmp = 0; // �� ����
	int group = 0; //�׷� ��

	while (true) {
		if (tmp >= n) break;
		group++; 
		tmp += cnt++;
	}
	
	
	int first = 1 + n*(n - 1) / 2; //(n>=2�ϋ�)
	
	return group-1;
	
}

int main() {
	int X;
	cin >> X;
	cout << findRule(X) <<endl;

}