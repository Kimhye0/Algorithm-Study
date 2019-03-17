#include <iostream>
#include <vector>
#define START 2
using namespace std;

vector <int> depth;

int findDepth(long long n) {
	int depth = 1;
	long long range = 1; //[2,7]6°³, [8,19]12°³, [20,37]18°³
	long long tmp = 1;

	while (true) {
		if (range >= n) {
			break;
		}
		tmp = 6 * (depth++);
		range += tmp;
	}
	return depth;
}

int main() {
	long long N;
	cin >> N;
	cout << findDepth(N) <<endl;
	
}