#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string str;
	getline(cin, str);
	int cnt = 1;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		if (str.at(i) == ' ') {
			cnt++;
		}
		
	}
	if (str.at(0) == ' ') {
		cnt--;
	}
	if (str.at(len - 1) == ' ') {
		cnt--;
	}
	cout << cnt << endl;

	return 0;
}