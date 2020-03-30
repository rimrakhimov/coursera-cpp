#include <iostream>
#include <sstream>
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
