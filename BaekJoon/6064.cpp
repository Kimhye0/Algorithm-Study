#include <iostream>
#include <algorithm>

using namespace std;

int M, N, x, y;

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int LCM(int a, int b)

{
	return (a * b) / GCD(a, b);
}


int main(void)

{
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		cin >> M >> N >> x >> y;
		int maxYear = LCM(M, N);
		while (true)
		{
			if (x > maxYear || (x - 1) % N + 1 == y)
				break;
			x += M;
		}
		if (x > maxYear)
			cout << -1 << "\n";
		else
			cout << x << "\n";
	}
	return 0;
}