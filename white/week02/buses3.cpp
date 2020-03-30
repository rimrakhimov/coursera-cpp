#include <iostream>
#include <map>
#include <set>

using namespace std;

bool ElementExists(const map<set<string>, int>& mapping, const set<string>& element) {
	return mapping.count(element) > 0;
}

int main() {
	int q; cin >> q;

	map<set<string>, int> routes_to_buses;

	int n;
	for (int i = 0; i < q; ++i) {
		cin >> n;

		set<string> stops;
		for (int i = 0; i < n; ++i) {
			string stop; cin >> stop;
			stops.insert(stop);
		}

		int route;
		if (ElementExists(routes_to_buses, stops)) {
			route = routes_to_buses[stops];
			cout << "Already exists for " << route << endl;
		} else {
			route = routes_to_buses.size() + 1;
			routes_to_buses[stops] = route;
			cout << "New bus " << route << endl;
		}
	}

	return 0;
}
