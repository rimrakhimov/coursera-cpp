#include <vector>
#include <string>
/* #include <iostream>

using namespace std; */

bool IsPalindrom(const string s) {
	int size = s.size();

	for (int i = 0; i < size / 2; ++i) {
		if (s[i] != s[(size-1) - i]) {
			return false;
		}
	}

	return true;
}

vector<string> PalindromFilter(const vector<string> words, int minLength) {
	vector<string> res;

	for (string w : words) {
		if (w.size() >= minLength && IsPalindrom(w)) {
			res.push_back(w);
		}
	}

	return res;
}

/* int main() {
	string s;
	cin >> s;

	cout << IsPalindrom(s) << endl;
	return 0;
} */
