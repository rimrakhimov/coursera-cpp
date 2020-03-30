#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	vector<int> temperature(n);
	for (auto& t : temperature) {
		cin >> t;
		sum += t;
	}

	int mean = sum / n;

	int k = 0;
	vector<int> indexes;
	for (int i = 0; i < temperature.size(); ++i) {
		if (temperature[i] > mean) {
			++k;
			indexes.push_back(i);
		}
	}

	cout << k << endl;
	for (auto& i : indexes) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
