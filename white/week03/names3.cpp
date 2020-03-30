// #include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person {
	public:
		Person(string first_name, string last_name, int year) {
			birth_first_name = first_name;
			birth_last_name = last_name;
			birth_year = year;

			year_to_first_name[year] = first_name;
			year_to_last_name[year] = last_name;
		}

  	void ChangeFirstName(int year, const string& first_name) {
			if (year >= birth_year) {
				year_to_first_name[year] = first_name;
			}
		}

  	void ChangeLastName(int year, const string& last_name) {
			if (year >= birth_year) {
				year_to_last_name[year] = last_name;
			}
		}

  	string GetFullName(int year) const {
			if (year < birth_year) {
				return "No person";
			} else {
				string first_name = GetName(year_to_first_name, year);
				string last_name = GetName(year_to_last_name, year);
				return first_name + " " + last_name;
			}
		}

		string GetFullNameWithHistory(int year) const {
			if (year < birth_year) {
				return "No person";
			} else {
				vector<string> first_names = GetAllNames(year_to_first_name, year);
				vector<string> last_names = GetAllNames(year_to_last_name, year);

				string format_first_names = FormatNames(first_names);
				string format_last_names = FormatNames(last_names);

				return format_first_names + " " + format_last_names;
			}
		}

	private:
		string birth_first_name;
		string birth_last_name;
		int birth_year;

		map<int, string> year_to_first_name;
		map<int, string> year_to_last_name;

		string GetName(const map<int, string>& mapping, int year) const {
			string name;
			for (const auto& item : mapping) {
				if (year >= item.first) {
					name = item.second;
				} else {
					break;
				}
			}
			return name;
		}

		vector<string> GetAllNames(const map<int, string>& mapping, int year) const {
			vector<string> names;
			for (const auto& item : mapping) {
				if (year >= item.first) {
					if (names.size() < 1) {
						names.push_back(item.second);
					} else if (item.second != names[names.size() - 1]) {
						names.push_back(item.second);
					}
				} else {
					break;
				}
			}
			return names;
		}

		string FormatNames(const vector<string> names) const {
			int size = names.size();
			string format_names = names[size - 1];
			if (size > 1) {
				format_names += " (";
				for (int i = size - 2; i > 0; --i) {
					format_names += names[i] + ", ";
				}
				format_names += names[0];
				format_names += ")";
			}
			return format_names;
		}
};

/* int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
} */
