#include <iostream>
#include <cstdlib>
#include <algorithm>
#define LENGTH 9
using namespace std;

int sum(int arr[],int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {

	int dwarfs[9] = { 0, };

	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
	}
	int notDwarfs = sum(dwarfs, LENGTH)-100;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarfs[i] + dwarfs[j] == notDwarfs) {
				dwarfs[i] = 0;
				dwarfs[j] = 0;
				sort(dwarfs, dwarfs + 9);
				for (int i = 2; i < LENGTH; i++) {
					cout << dwarfs[i] << endl;
				}
			}
		}
		
	}
	//sort(dwarfs, dwarfs + 9);
	//for (int i = 2; i < LENGTH; i++) {
	//	cout << dwarfs[i] << endl;
	//}
	return 0;
}