#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

struct Day {
	explicit Day(int new_value) {
		value = new_value;
	}
	int	value;
};

struct Month {
	explicit Month(int new_value) {
		value = new_value;
	}
	int value;
};

struct Year {
	explicit Year(int new_value) {
		value = new_value;
	}
	int value;
};

class Date {
public:
	Date() {
		year = 1970;
		month = 1;
		day = 1;
	}

	Date(Year new_year, Month new_month, Day new_day) {
		year = new_year.value;
		month = new_month.value;
		day = new_day.value;
		CheckDate();
	}

  int GetYear() const {
		return year;
	}
  int GetMonth() const {
		return month;
	}
  int GetDay() const {
		return day;
	}

private:
	int year, month, day;

	void CheckDate() {
		if (month < 1 || month > 12) {
			ostringstream error;
			error << "Month value is invalid: " << month;
			throw invalid_argument(error.str());
		}
		if (day < 1 || day > 31) {
			ostringstream error;
			error << "Day value is invalid: " << day;
			throw invalid_argument(error.str());
		}
	}
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		} else {
			return lhs.GetMonth() < rhs.GetMonth();
		}
	} else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

// Skips '+' sign in the beginning of number
void SkipPlusSign(istream& stream) {
	if (stream.peek() == '+') {
		stream.ignore(1);
	}
}

void ThrowWrongDateFormatException(const string& date) {
	ostringstream error;
	error << "Wrong date format: " << date;
	throw invalid_argument(error.str());
}

istream& operator>>(istream& input, Date& date) {
	string inp; input >> inp;
	istringstream stream(inp);

	int year, month, day;
	char sep1, sep2;

	SkipPlusSign(stream);
	if (! (stream >> year >> sep1 && sep1 == '-')) {
		ThrowWrongDateFormatException(inp);
	}
	SkipPlusSign(stream);
	if (! (stream >> month >> sep2 && sep2 == '-')) {
		ThrowWrongDateFormatException(inp);
	}
	SkipPlusSign(stream);
	if (! (stream >> day)) {
		ThrowWrongDateFormatException(inp);
	}
	if (! stream.eof()) {
		ThrowWrongDateFormatException(inp);
	}

	date = Date(Year(year), Month(month), Day(day));

	return input;
}

ostream& operator<<(ostream& output, const Date& date) {
	output << setfill('0');
	output << setw(4) << date.GetYear() << '-'
			<< setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();

	return output;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
		events[date].insert(event);
	}

  bool DeleteEvent(const Date& date, const string& event) {
		if (events.count(date) == 0) {	// date has no events
			return false;
		}
		if (events.at(date).count(event) == 0) {	// event has not happened in the date
			return false;
		}

		events.at(date).erase(event);	// event happened in the date
		return true;
	}

  int DeleteDate(const Date& date) {
		int n = events[date].size();
		events.erase(date);
		return n;
	}

	set<string> Find(const Date& date) const {
		if (events.count(date) > 0) {	// date exists
			return events.at(date);
		} else {
			return {};
		}
	}

  void Print() const {
		for (const auto& item : events) {
			for (const auto& event : item.second) {
				cout << item.first << ' ' << event << endl;
			}
		}

	}

private:
	map<Date, set<string>> events;
};

// pass exception to main function if happens
Date ReadDate(const string& date_string) {
	Date date;
	istringstream date_stream(date_string);

	try {
		date_stream >> date;
	} catch (const invalid_argument& e) {
			cout << e.what() << endl;
			exit(1);
	}

	return date;
}

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
		istringstream command_stream(command);
		string operation;

		// the line is empty
		if (! (command_stream >> operation)) {
			continue;
		}

		if (operation == "Add") {
			string date_string, event;
			command_stream >> date_string >> event;

			Date date = ReadDate(date_string);
			db.AddEvent(date, event);

		} else if (operation == "Del") {
			string date_string;
			command_stream >> date_string;

			Date date;
			date = ReadDate(date_string);

			string event;
			if (command_stream >> event) {	// event is specified
				bool deleted = db.DeleteEvent(date, event);
				if (deleted) {
					cout << "Deleted successfully" << endl;
				} else {
					cout << "Event not found" << endl;
				}
			} else {
				int deleted_n = db.DeleteDate(date);
				cout << "Deleted " << deleted_n << " events" << endl;
			}

		} else if (operation == "Find") {
			string date_string;
			command_stream >> date_string;

			Date date;
			date = ReadDate(date_string);

			set<string> events = db.Find(date);
			for (const auto& event : events) {
				cout << event << endl;
			}

		} else if (operation == "Print") {
			db.Print();

		} else {
			cout << "Unknown command: " << operation << endl;
			exit(1);
		}

  }

  return 0;
}

