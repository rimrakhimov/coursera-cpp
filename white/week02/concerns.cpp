#include <iostream>
#include <vector>

using namespace std;

int main() {
	const vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int q;
	cin >> q;

	int month = 0;
	vector<vector<string>> concerns(days_in_months[month]);

	string operation;
	for (int i = 0; i < q; ++i) {
		cin >> operation;
		if (operation == "DUMP") {
			int day;
			cin >> day;

			cout << concerns[day - 1].size() << " ";
			for (const auto& task : concerns[day - 1]) {
				cout << task << " ";
			}
			cout << endl;
		} else if (operation == "ADD") {
			int day; string task;
			cin >> day >> task;

			concerns[day - 1].push_back(task);
		} else if (operation == "NEXT") {
			int next_month = (month + 1) % 12;

			if (days_in_months[next_month] < days_in_months[month]) {
				int last_day_in_next_month = days_in_months[next_month];
				for (int day = last_day_in_next_month; day < days_in_months[month]; ++day) {
					concerns[last_day_in_next_month-1].insert(
							concerns[last_day_in_next_month-1].end(),
							concerns[day].begin(),
							concerns[day].end()
					);
				}
				concerns.resize(days_in_months[next_month]);
			} else {
				concerns.resize(days_in_months[next_month]);
			}
			month = next_month;
		}
	}

	return 0;
}
