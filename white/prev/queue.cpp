#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> queue;

    string operation;
    for (int i = 0; i < n; ++i) {
        cin >> operation;
        if (operation == "WORRY") {
            int code;
            cin >> code;
            queue[code] = 1;
        } else if (operation == "QUIET") {
            int code;
            cin >> code;
            queue[code] = 0;
        } else if (operation == "COME") {
            int number;
            cin >> number;
            if (number > 0) {
                for (int j = 0; j < number; ++j) {
                    queue.push_back(0);
                }
            } else {
                for (int j = 0; j < -number; ++j) {
                    queue.pop_back();
                }
            }
        } else {
            int k = 0;
            for (int j = 0; j < queue.size(); ++j) {
                k += queue[j];
            }
            cout << k << endl;
        }
    }
    return 0;
}