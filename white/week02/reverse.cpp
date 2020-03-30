//#include <vector>

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Reverse(vector<int>& v) {
	int size = v.size();
	for (int i = 0; i < size / 2; ++i) {
		Swap(v[i], v[size - 1 - i]);
	}
}
