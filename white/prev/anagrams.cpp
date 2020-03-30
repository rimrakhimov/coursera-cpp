#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
    map<char, int> counter;
    for (char c : word) {
        ++counter[c];
    }
    return counter;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string first, second;
        cin >> first >> second;
        if (BuildCharCounters(first) == BuildCharCounters(second)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}