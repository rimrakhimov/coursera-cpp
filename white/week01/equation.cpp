#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;

	if (a != 0) {
		double disc = b*b - 4 * a * c;
		if (disc == 0) {
			cout << -b / (2*a) << endl;
		} else if (disc > 0) {
			double sqrt_disc = sqrt(disc);
			cout << (-b - sqrt_disc) / (2 * a) << " ";
			cout << (-b + sqrt_disc) / (2 * a) << endl;
		}
	} else {
		if (b != 0) {
			cout << -c / b << endl;
		} else if (c == 0) {
	 		cout << "inf" << endl;
		}
	}

	return 0;
}
