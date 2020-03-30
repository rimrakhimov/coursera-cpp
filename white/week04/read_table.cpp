#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void ReadLine(ifstream& input, int columns) {
	int value;
	for (int i = 0; i < columns - 1; ++i) {
		input >> value;
		cout << setw(10) << value << ' ';
		input.ignore(1);
	}
	input >> value;
	cout << setw(10) << value;
	input.ignore(1);
}

int main() {
	ifstream input("input.txt");
//	ofstream output("output.txt");

	int m, n;
	input >> m >> n;

	int value;
	for (int i = 0; i < m - 1; ++i) {
		ReadLine(input, n);
		cout << endl;
	}
	ReadLine(input, n);

	return 0;
}
