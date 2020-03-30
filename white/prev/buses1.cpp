#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void PrintVector(const vector<string>& vector_to_print) {
    for (const string& item : vector_to_print) {
        cout << item << ' ';
    }
    cout << endl;   
}

int main() {
    int n; cin >> n;

    map<string, vector<string>> buses_to_routes;
    map<string, vector<string>> stops_to_buses;
    
    for (int i = 0; i < n; ++i) {
        string operation; cin >> operation;
        if (operation == "NEW_BUS") {
            string bus; int stop_count;
            cin >> bus >> stop_count;
            string stop;
            for (int j = 0; j < stop_count; ++j) {
                cin >> stop;
                buses_to_routes[bus].push_back(stop);
                stops_to_buses[stop].push_back(bus);
            }
        } else if (operation == "BUSES_FOR_STOP") {
            string stop; cin >> stop;
            if (stops_to_buses.count(stop) == 0) {
                cout << "No stop" << endl;
            } else {
                PrintVector(stops_to_buses[stop]);
            }
        } else if (operation == "STOPS_FOR_BUS") {
            string bus; cin >> bus;
            if (buses_to_routes.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (const string& stop : buses_to_routes[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (stops_to_buses[stop].size() == 1) {
                        cout << "no interchange" << endl;
                    } else {
                        for (const string& item : stops_to_buses[stop]) {
                            if (item != bus)
                                cout << item << ' ';
                        }
                        cout << endl;
                    }
                }
            }
        } else if (operation == "ALL_BUSES") {
            if (buses_to_routes.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for (const auto& bus_item : buses_to_routes) {
                    cout << "Bus " << bus_item.first << ": ";
                    PrintVector(bus_item.second);
                }
            }
        }
    }
    return 0;
}