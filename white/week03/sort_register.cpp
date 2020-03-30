#include <iostream>
#include <algorithm>
#include <vector>
//#include <stdio.h>

using namespace std;

int main() {
	int n; cin >> n;

	vector<string> v(n);
	for (auto& elem : v) {
		cin >> elem;
	}

	sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
				int size = min(s1.size(), s2.size());
				for (int i = 0; i < size; ++i) {
					char c1 = tolower(s1[i]);
					char c2 = tolower(s2[i]);
					if (c1 < c2) {
						return true;
					} else if (c2 < c1) {
						return false;
					}
				}
				return (s1.size() == size);
			});

	for (const auto& elem : v) {
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}
