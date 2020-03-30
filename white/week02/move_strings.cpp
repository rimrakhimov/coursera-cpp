#include <vector>
#include <string>

void MoveStrings(vector<string>& source, vector<string>& dest) {
	for (auto w : source) {
		dest.push_back(w);
	}
	source.clear();
}
