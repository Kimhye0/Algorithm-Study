#include <iostream>
#include <string>
#include <stack>
using namespace std;

void vps(string str) {

	stack <char> s;
	int len = str.size();
	for (int i = 0; i <len; i++) {
		if(str[i]=='(') s.push(str[i]);
		else if (str[i] == ')') {
			if (s.empty()) {
				cout << "NO" << endl;
				return;
			}
			else s.pop();
		}
	}
	if (s.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;

	return;
}

int main() {
	
	int size;
	string str;

	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> str;
		vps(str);
	}

	return 0;
}