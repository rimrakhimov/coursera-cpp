#include <iostream>
#include <vector>

using namespace std;

struct Student {
	string first_name;
	string last_name;
	int birth_day;
	int birth_month;
	int birth_year;
};

int main() {
	vector<Student> students;

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string first_name, last_name;
		int birth_day, birth_month, birth_year;
		cin >> first_name >> last_name >> birth_day >> birth_month >> birth_year;

		students.push_back({first_name, last_name, birth_day, birth_month, birth_year});
	}

	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		string operation; int k;
		cin >> operation >> k;
		if (operation == "name" && k > 0 && k <= n) {
			--k;
			cout << students[k].first_name << ' ' << students[k].last_name << endl;
		} else if (operation == "date" && k > 0 && k <= n) {
			--k;
			cout << students[k].birth_day << '.' << students[k].birth_month << '.' << students[k].birth_year << endl;
		} else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}
