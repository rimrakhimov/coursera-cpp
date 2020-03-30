#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool ElementExists(const map<vector<string>, int>& mapping, const vector<string>& element) {
	return mapping.count(element) > 0;
}

int main() {
	int q; cin >> q;

	map<vector<string>, int> routes_to_buses;

	int n;
	for (int i = 0; i < q; ++i) {
		cin >> n;

		vector<string> stops(n);
		for (auto& stop : stops) {
			cin >> stop;
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
