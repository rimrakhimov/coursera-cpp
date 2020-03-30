#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> result;
	while (n > 0) {
		result.push_back(n % 2 == 1);
		n /= 2;
	}

	for (int i = result.size()-1; i >= 0; --i) {
		cout << result[i];
	}
	cout << endl;

	return 0;
}
