#include <iostream>
#include <string>
#include <map>

using namespace std;

string GetPositivity(int x) {
    return x > 0 ? "positive"
                 : (x == 0 ? "zero" : "negative");
}

int main() {
    cout << GetPositivity(-5);

    return 0;
}