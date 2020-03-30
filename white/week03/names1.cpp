// #include <iostream>
#include <map>
#include <climits>

using namespace std;

class Person {
	public:
  	void ChangeFirstName(int year, const string& first_name) {
			year_to_first_name[year] = first_name;
			if (min_first_name_year > year) {
				min_first_name_year = year;
			}
		}

  	void ChangeLastName(int year, const string& last_name) {
			year_to_last_name[year] = last_name;
			if (min_last_name_year > year) {
				min_last_name_year = year;
			}
		}

  	string GetFullName(int year) {
			if (year < min_first_name_year && year < min_last_name_year) {
				return "Incognito";
			} else if (year < min_first_name_year) {
				return GetLastName(year) + " " + "with unknown first name";
			} else if (year < min_last_name_year) {
				return GetFirstName(year) + " " + "with unknown last name";
			} else {
				return GetFirstName(year) + " " + GetLastName(year);
			}

		}

	private:
		map<int, string> year_to_first_name;
		map<int, string> year_to_last_name;

		int min_first_name_year = INT_MAX;
		int min_last_name_year = INT_MAX;

		string GetFirstName(int year) {
			string first_name;
			for (const auto& item : year_to_first_name) {
				if (year >= item.first) {
					first_name = item.second;
				} else {
					break;
				}
			}
			return first_name;
		}

		string GetLastName(int year) {
			string last_name;
			for (const auto& item : year_to_last_name) {
				if (year >= item.first) {
					last_name = item.second;
				} else {
					break;
				}
			}
			return last_name;
		}
};

/* int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
} */
