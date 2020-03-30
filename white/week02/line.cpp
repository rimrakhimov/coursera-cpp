#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<bool> worried;

	int n;
	cin >> n;

	string operation;
	int option;
	for (int i = 0; i < n; ++i) {
		cin >> operation;
		if (operation == "WORRY") {
			cin >> option;
			worried[option] = true;
		} else if (operation == "QUIET") {
			cin >> option;
			worried[option] = false;
		} else if (operation == "COME") {
			cin >> option;
			worried.resize(worried.size() + option);
		} else if (operation == "WORRY_COUNT") {
			cout << count(worried.begin(), worried.end(), true) << endl;
		}
	}

	return 0;
}
