#include <iostream>
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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
