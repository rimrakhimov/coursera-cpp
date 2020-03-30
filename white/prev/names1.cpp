#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {

struct FullName {
    string first_name = "";
    string last_name = "";
};

public:
    void ChangeFirstName(int year, const string& first_name) {
        first_name_changes[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_name_changes[year] = last_name;
    }
    string GetFullName(int year) {
        FullName current_name = GetLastKnownFullName(year);
        if (current_name.first_name == "" && current_name.last_name == "")
            return "Incognito";
        else if (current_name.first_name == "")
            return current_name.last_name + " with unknown first name";
        else if (current_name.last_name == "")
            return current_name.first_name + " with unknown last name";
        else
            return current_name.first_name + ' ' + current_name.last_name;
  }
private:
    map<int, string> first_name_changes;
    map<int, string> last_name_changes;

    FullName GetLastKnownFullName(int year) {
        FullName known_full_name;
        known_full_name.first_name = CombineChanges(year, first_name_changes);
        known_full_name.last_name = CombineChanges(year, last_name_changes);
        return known_full_name;
    }

    string CombineChanges(int year, const map<int, string>& changes) {
        string result = "";
        for (const auto& item : changes) {
            if (item.first > year) {
                return result;
            }
            result = item.second;
        }
        return result;
    }
};

int main() {
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
}