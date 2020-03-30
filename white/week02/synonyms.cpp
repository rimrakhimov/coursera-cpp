#include <iostream>
#include <map>
#include <set>

using namespace std;

bool ElementExists(const map<string, set<string>>& mapping, const string& elem) {
	return mapping.count(elem) > 0;
}

int main() {
	int q; cin >> q;

	map <string, set<string>> word_to_syns;

	string operation;
	for (int i = 0; i < q; ++i) {
		cin >> operation;

		if (operation == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;

			word_to_syns[word1].insert(word2);
			word_to_syns[word2].insert(word1);
		} else if (operation == "COUNT") {
			string word; cin >> word;

			if (! ElementExists(word_to_syns, word)) {	// to not create empty set
				cout << 0 << endl;
			} else {
				cout << word_to_syns[word].size() << endl;
			}
		} else if (operation == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;

			if (! ElementExists(word_to_syns, word1)) {	// to not create empty set
				cout << "NO" << endl;
			} else {
			  cout << (word_to_syns[word1].count(word2) ? "YES" : "NO") << endl;
			}
		}
	}

	return 0;
}
