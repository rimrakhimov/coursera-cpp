#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool ElementExists(const map<string, vector<string>>& mapping, const string& key) {
	return mapping.count(key) != 0;
}

void PrintVector(const vector<string>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
}

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> bus_to_stops;
	map<string, vector<string>> stop_to_buses;

	string operation;
	for (int i = 0; i < q; ++i) {
		cin >> operation;
		if (operation == "NEW_BUS") {
			string bus; cin >> bus;
			int stop_count; cin >> stop_count;

			string stop;
			for (int j = 0; j < stop_count; ++j) {
				cin >> stop;
				bus_to_stops[bus].push_back(stop);
				stop_to_buses[stop].push_back(bus);
			}

		} else if (operation == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			if (ElementExists(stop_to_buses, stop)) {
				PrintVector(stop_to_buses[stop]);
			} else {
				cout << "No stop" << endl;
			}
		} else if (operation == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if (ElementExists(bus_to_stops, bus)) {
				const vector<string>& stops = bus_to_stops[bus];
				for (const auto& stop : stops) {
					cout << "Stop " << stop << ": ";
					const vector<string>& buses = stop_to_buses[stop];
					if (buses.size() == 1) {	// only 'bus' goes through the stop
						cout << "no interchange" << endl;
					} else {
						for (const auto& b : buses) {
							if (b != bus) {
								cout << b << " ";
							}
						}
						cout << endl;
					}
				}
			} else {
				cout << "No bus" << endl;
			}

		} else if (operation == "ALL_BUSES") {
			if (bus_to_stops.size() > 0) {	// at least one bus exists
				for (const auto& item : bus_to_stops) {
					cout << "Bus " << item.first << ": ";
					PrintVector(item.second);
				}
			} else {
				cout << "No buses" << endl;
			}
		}
	}

	return 0;
}
