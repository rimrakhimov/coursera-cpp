#include <iostream>
#include <exception>
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
			 if (new_denominator == 0) {
			 	throw invalid_argument("");
			 }
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
	if (r2.Numerator() == 0) {
		throw domain_error("");
	}

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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
