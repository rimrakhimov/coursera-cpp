#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void Print(const vector<string>& vec) {
    for (const auto& i : vec) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    vector<string> vec(n);
    for (auto& i : vec) {
        cin >> i;
    }
    sort(begin(vec), end(vec), [](const string& a, const string& b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (tolower(a[i]) < tolower(b[i])) {
                return true;
            } else if (tolower(a[i]) > tolower(b[i])) {
                return false;
            }
        }
        if (a.size() == b.size() || a.size() == len) {
            return true;
        }
        return false;
    });
    
    Print(vec);
    return 0;
}