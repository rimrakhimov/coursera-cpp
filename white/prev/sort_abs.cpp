#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Print(const vector<int>& vec) {
    for (const auto& i : vec) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto& i : vec) {
        cin >> i;
    }
    sort(begin(vec), end(vec), [](int x, int y) {
        return abs(x) < abs(y);
    });
    
    Print(vec);
    return 0;
}