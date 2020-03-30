#include <iostream>

using namespace std;

int main() {
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	double total_sum;
	if (n > b) {
		total_sum = n * ((100 - y) / 100.0);
	} else if (n > a) {
		total_sum = n * ((100 - x) / 100.0);
	} else {
		total_sum = n;
	}

	cout << total_sum << endl;

	return 0;
}
