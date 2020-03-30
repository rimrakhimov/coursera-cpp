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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
