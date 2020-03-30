#include <iostream>
#include <string>

using namespace std;

int main() {
	string inp;
	cin >> inp;


	int met = 0;
	int i;
	for (i = 0; i < inp.size(); ++i) {
		if (inp[i] == 'f') {
			met++;
		}

		if (met == 2) {
			break;
		}
	}

	if (met == 2) {
		cout << i << endl;
	} else if (met == 1) {
		cout << -1 << endl;
	} else {
		cout << -2 << endl;
	}

	return 0;
}
