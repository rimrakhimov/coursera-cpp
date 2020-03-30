#include <iostream>
#include <set>

using namespace std;

int main() {
	int n; cin >> n;

	set<string> uniq_words;

	string word;
	for (int i = 0; i < n; ++i) {
		cin >> word;
		uniq_words.insert(word);
	}

	cout << uniq_words.size() << endl;

	return 0;
}
