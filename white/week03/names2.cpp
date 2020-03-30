// #include <iostream>
#include <map>
#include <vector>

using namespace std;

class Person {
	public:
  	void ChangeFirstName(int year, const string& first_name) {
			year_to_first_name[year] = first_name;
		}

  	void ChangeLastName(int year, const string& last_name) {
			year_to_last_name[year] = last_name;
		}

  	string GetFullName(int year) {
			string first_name = GetName(year_to_first_name, year);
			string last_name = GetName(year_to_last_name, year);
			if (first_name.empty() && last_name.empty()) {
				return "Incognito";
			} else if (first_name.empty()) {
				return last_name + " " + "with unknown first name";
			} else if (last_name.empty()) {
				return first_name + " " + "with unknown last name";
			} else {
				return first_name + " " + last_name;
			}
		}

		string GetFullNameWithHistory(int year) {
			vector<string> first_names = GetAllNames(year_to_first_name, year);
			vector<string> last_names = GetAllNames(year_to_last_name, year);

			if (first_names.size() == 0 && last_names.size() == 0) {
				return "Incognito";
			} else if (first_names.size() == 0) {
				string format_last_names = FormatNames(last_names);
				return format_last_names + " " + "with unknown first name";
			} else if (last_names.size() == 0) {
				string format_first_names = FormatNames(first_names);
				return format_first_names + " " + "with unknown last name";
			} else {
				string format_first_names = FormatNames(first_names);
				string format_last_names = FormatNames(last_names);
				return format_first_names + " " + format_last_names;
			}
		}

	private:
		map<int, string> year_to_first_name;
		map<int, string> year_to_last_name;

		string GetName(const map<int, string>& mapping, int year) {
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

		vector<string> GetAllNames(const map<int, string>& mapping, int year) {
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

		string FormatNames(const vector<string> names) {
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
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;

  return 0;
} */
