#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

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
        if (current_name.first_name.empty() && current_name.last_name.empty())
            return "Incognito";
        else if (current_name.first_name.empty())
            return current_name.last_name + " with unknown first name";
        else if (current_name.last_name.empty())
            return current_name.first_name + " with unknown last name";
        else
            return current_name.first_name + ' ' + current_name.last_name;
    }

    string GetFullNameWithHistory(int year) {
        vector<string> first_name_history = GetHistory(year, first_name_changes);
        vector<string> last_name_history = GetHistory(year, last_name_changes);
        int first_name_history_size = first_name_history.size();
        int last_name_history_size = last_name_history.size();
        if (first_name_history_size == 0 && last_name_history_size == 0)
            return "Incognito";
        else if (first_name_history_size == 0)
            return ParseHistory(last_name_history) + " with unknown first name";
        else if (last_name_history_size == 0)
            return ParseHistory(first_name_history) + " with unknown last name";
        else
            return ParseHistory(first_name_history) + ' ' + ParseHistory(last_name_history);
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

    const string CombineChanges(int year, const map<int, string>& changes) {
        string result = "";
        for (const auto& item : changes) {
            if (item.first > year) {
                return result;
            }
            result = item.second;
        }
        return result;
    }

    const vector<string> GetHistory(int year, const map<int, string>& changes) {
        vector<string> result;
        for (const auto& item : changes) {
            if (item.first > year) {
                break;
            }
            result.push_back(item.second);
        }
        return result;
    }

    const string ParseHistory(const vector<string>& history) {
        int history_size = history.size();
        string result = history[history_size-1];
        if (history_size > 1) {
            result += " (";
            for (int i = history_size - 2; i >= 0; --i) {
                if (history[i] != history[i+1]) {
                    result += history[i] + ", ";
                }
            }
            result = result.substr(0, result.size()-2);
            if (result != history[history_size-1]) {
                result += ")";
            }
        }
        return result;
    }
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
