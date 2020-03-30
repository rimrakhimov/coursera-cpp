#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
				denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
       numerator = new_numerator;
			 denominator = new_denominator;
			 UpdateRational();
    }

   int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
		int denominator;

		void UpdateRational() {
			int divisor = abs(__gcd(numerator, denominator));	// to be always non-negative
			int sign = denominator < 0 ? -1 : 1;
			numerator /= sign * divisor;
			denominator /= sign * divisor;
		}
};

bool operator==(const Rational& r1, const Rational& r2) {
	return (
			r1.Numerator() == r2.Numerator() &&
			r1.Denominator() == r2.Denominator()
		);
}

Rational operator+(const Rational& r1, const Rational& r2) {
	return Rational(
			r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(),
			r1.Denominator() * r2.Denominator()
		);
}

Rational operator-(const Rational& r1, const Rational& r2) {
	return Rational(
			r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(),
			r1.Denominator() * r2.Denominator()
		);
}

Rational operator*(const Rational& r1, const Rational& r2) {
	return Rational(
			r1.Numerator() * r2.Numerator(),
			r1.Denominator() * r2.Denominator()
		);
}

Rational operator/(const Rational& r1, const Rational& r2) {
	return Rational(
			r1.Numerator() * r2.Denominator(),
			r1.Denominator() * r2.Numerator()
		);
}

istream& operator>>(istream& input, Rational& r) {
	if (input) {
		int numerator, denominator;
		if (input >> numerator) {
			if (input.peek() == '/') {
				input.ignore(1);
				if (input >> denominator) {
					r = Rational(numerator, denominator);
				}
			}
		}
	}

	return input;
}

ostream& operator<<(ostream& output, const Rational& r) {
	output << r.Numerator() << '/' << r.Denominator();

	return output;
}

bool operator<(const Rational& r1, const Rational& r2) {
	return (r1 - r2).Numerator() < 0;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
