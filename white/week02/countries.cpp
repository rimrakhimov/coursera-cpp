#include <iostream>
#include <map>

using namespace std;

bool CountryExists(const map<string, string>& countries, const string& country) {
	return countries.count(country) != 0;
}

int main() {
	int q;
	cin >> q;

	map<string, string> country_to_capital;

	string operation;
	for (int i = 0; i < q; ++i) {
		cin >> operation;
		if (operation == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			if (! CountryExists(country_to_capital, country)) {
				country_to_capital[country] = new_capital;
				cout << "Introduce new country " << country <<
					" with capital " << new_capital << endl;
			} else if (country_to_capital[country] != new_capital) {
				const string old_capital = country_to_capital[country];
				country_to_capital[country] = new_capital;
				cout << "Country " << country << " has changed its capital from "
					<< old_capital << " to " << new_capital << endl;
			} else {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
		} else if (operation == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if (old_country_name == new_country_name ||
					! CountryExists(country_to_capital, old_country_name) ||
					CountryExists(country_to_capital, new_country_name) > 0)
			{
				cout << "Incorrect rename, skip" << endl;
			} else {
				const string capital = country_to_capital[old_country_name];
				country_to_capital.erase(old_country_name);
				country_to_capital[new_country_name] = capital;
				cout << "Country " << old_country_name << " with capital " <<
					capital << " has been renamed to " << new_country_name << endl;
			}
		} else if (operation == "ABOUT") {
			string country;
			cin >> country;

			if (CountryExists(country_to_capital, country)) {
				const string capital = country_to_capital[country];
				cout << "Country " << country << " has capital " << capital << endl;
			} else {
				cout << "Country " << country << " doesn't exist" << endl;
			}
		} else if (operation == "DUMP") {
			if (country_to_capital.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (const auto& item : country_to_capital) {
					cout << item.first << "/" << item.second << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
