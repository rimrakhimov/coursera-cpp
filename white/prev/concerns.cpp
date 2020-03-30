#include <iostream>
#include <string>
#include <vector>

using namespace std;

int daysInMonth(int month) {
    switch (month) {
        case 0:
            return 31;
        case 1:
            return 28;
        case 2:
            return 31;
        case 3:
            return 30;
        case 4:
            return 31;
        case 5:
            return 30;
        case 6:
            return 31;
        case 7:
            return 31;
        case 8:
            return 30;
        case 9:
            return 31;
        case 10:
            return 30;
        case 11:
            return 31;
        default:
            return -1;
    } 
}

int main() {
    int n;
    cin >> n;

    int currentMonth = 0;
    int daysInCurrentMonth = daysInMonth(currentMonth);
    // vector of tasks per month
    vector<vector<string>> tasks(daysInCurrentMonth);

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation == "DUMP") {
            int date; cin >> date;
            int tasksAmount = tasks[date-1].size();
            cout << tasksAmount << ' ';
            for (int j = 0; j < tasksAmount; ++j) {
                cout << tasks[date-1][j] << ' ';
            }
            cout << endl;
        } else if (operation == "ADD") {
            int date; cin >> date;
            string task; cin >> task;
            tasks[date-1].push_back(task);
        } else {
            ++currentMonth %= 12;
            int daysInNextMonth = daysInMonth(currentMonth);
            for (int j = daysInNextMonth; j < daysInCurrentMonth; ++j) {
                tasks[daysInNextMonth-1].insert(
                    end(tasks[daysInNextMonth-1]),
                    begin(tasks[j]), end(tasks[j])
                );
            }
            tasks.resize(daysInNextMonth, vector<string> (0));
            
            daysInCurrentMonth = daysInNextMonth;

        }
    }

    return 0;
}