#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n);
	for (auto& elem : v) {
		cin >> elem;
	}

	sort(v.begin(), v.end(), [](int a, int b) { return abs(a) < abs(b); });

	for (const auto& elem : v) {
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}
