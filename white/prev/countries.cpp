#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    map<string, string> capitals;

    for (int i = 0; i < n; ++i) {
        string operation; cin >> operation;
        if (operation == "DUMP") {
            if (capitals.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (auto& pair : capitals) {
                    cout << pair.first << '/' << pair.second << ' ';
                }
                cout << endl;
            }
        } else if (operation == "ABOUT") {
            string country; cin >> country;
            if (capitals.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            }
        } else if (operation == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name ||
                capitals.count(old_country_name) == 0 ||
                capitals.count(new_country_name) > 0
            ) {
                cout << "Incorrect rename, skip" << endl;
            } 
            else {
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
                cout << "Country " << old_country_name << " with capital " <<
                    capitals[new_country_name] << " has been renamed to " << new_country_name << endl;
            }
        } else if (operation == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (capitals.count(country) == 0) {
                capitals[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else if (capitals[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " <<
                    capitals[country] << " to " << new_capital << endl;
                capitals[country] = new_capital;
            }
        }
    }

    return 0;
}