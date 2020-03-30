#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;

	return GCD(b, a % b);
}

int main() {
	int a, b;
	while (true) {
		cout << "\nWrite the rational: " << endl;
		cin >> a >> b;
		cout << "The gcd is: ";
		int gcd = __gcd(a, b);
		cout << gcd << endl;
		cout << "The rational is: " << a / gcd << "/" << b / gcd << endl;
	}
	return 0;
}
