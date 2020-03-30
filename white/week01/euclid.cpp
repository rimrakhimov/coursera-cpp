#include <iostream>

using namespace std;

int euclid(int a, int b) {
	// a should be always not less than b
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}

	// base case
	if (b == 0) {
		return a;
	}

	return euclid (b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << euclid(a, b) << endl;

	return 0;
}
