#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string KMP;
	cin >> str;
	
	int len = str.length();
	KMP += str[0];
	for (int i = 0; i < len; i++) {
		
		if (str[i] == '-') {
			char ch = str[i + 1];
			KMP += ch;
		}
		
	}

	cout << KMP <<"\n";
	return 0;
}