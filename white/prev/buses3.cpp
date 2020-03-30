#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;

    map<set<string>, int> routes;

    for (int i = 0; i < n; ++i) {
        int stops_in_route; cin >> stops_in_route;
        set<string> route;
        for (int j = 0; j < stops_in_route; ++j) {
            string stop; cin >> stop;
            route.insert(stop);
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