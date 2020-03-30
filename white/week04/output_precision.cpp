#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");

	if (input) {
		cout << fixed << setprecision(3);

		double value;
		while (input >> value) {
			cout << value << endl;
		}
	}

	return 0;
}
