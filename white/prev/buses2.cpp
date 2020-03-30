#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;

    map<vector<string>, int> routes;

    for (int i = 0; i < n; ++i) {
        int stops_in_route; cin >> stops_in_route;
        vector<string> route(stops_in_route);
        for (int j = 0; j < stops_in_route; ++j) {
            cin >> route[j];
        }
        if (routes.count(route) == 0) {
            int new_bus = routes.size() + 1;
            routes[route] = new_bus;
            cout << "New bus " << routes[route] << endl;
        } else {
            cout << "Already exists for " << routes[route] << endl;
        }
    }

    return 0;
}