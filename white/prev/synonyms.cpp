#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;

    map<string, set<string>> synonyms;

    string operation;
    for (int i = 0; i < n; ++i) {
        cin >> operation;
        if (operation == "ADD") {
            string first_word, second_word;
            cin >> first_word >> second_word;
            synonyms[first_word].insert(second_word);
            synonyms[second_word].insert(first_word);
        } else if (operation == "COUNT") {
            string word; cin >> word;
            if (synonyms.count(word) == 0) {
                cout << 0 << endl;
            } else {
                cout << synonyms[word].size() << endl;
            }
        } else if (operation == "CHECK") {
            string first_word, second_word;
            cin >> first_word >> second_word;
            if (synonyms.count(first_word) == 0) {
                cout << "NO" << endl;
            } else if (synonyms[first_word].count(second_word) == 0) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }


    return 0;
}