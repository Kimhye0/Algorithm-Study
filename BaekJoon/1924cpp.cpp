#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y;
	int cnt = 0;
	cin >> x >> y;

	char date[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < x; i++) {
		cnt += date[i - 1];
	}
	cnt += y;
	
	switch (cnt%7)
	{
	case 0:
		cout << "SUN" << endl;
		break;
	case 1:
		cout << "MON" << endl;
		break;
	case 2:
		cout << "TUE" << endl;
		break;
	case 3:
		cout << "WED" << endl;
		break;
	case 4:
		cout << "THU" << endl;
		break;
	case 5:
		cout << "FRI" << endl;
		break;
	case 6:
		cout << "SAT" << endl;
		break;
	}

	return 0;
}