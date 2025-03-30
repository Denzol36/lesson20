#include <iostream>
#include <cmath>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    void reduce() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
    }
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Denominator cannot be zero!" << endl;
            denominator = 1;
        }
        reduce();
    }
    static Fraction add(const Fraction& frac1, const Fraction& frac2) {
        int num = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
        int denom = frac1.denominator * frac2.denominator;
        return Fraction(num, denom);
    }
    static Fraction subtract(const Fraction& frac1, const Fraction& frac2) {
        int num = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
        int denom = frac1.denominator * frac2.denominator;
        return Fraction(num, denom);
    }
    static Fraction multiply(const Fraction& frac1, const Fraction& frac2) {
        int num = frac1.numerator * frac2.numerator;
        int denom = frac1.denominator * frac2.denominator;
        return Fraction(num, denom);
    }
    static Fraction divide(const Fraction& frac1, const Fraction& frac2) {
        if (frac2.numerator == 0) {
            cout << "Error: Division by zero!" << endl;
            return frac1;
        }
        int num = frac1.numerator * frac2.denominator;
        int denom = frac1.denominator * frac2.numerator;
        return Fraction(num, denom);
    }
    static bool isEqual(const Fraction& frac1, const Fraction& frac2) {
        return frac1.numerator == frac2.numerator && frac1.denominator == frac2.denominator;
    }
    double toDecimal() const {
        return static_cast<double>(numerator) / denominator;
    }
    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        do {
            cout << "Enter denominator (non-zero): ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Denominator cannot be zero, try again!" << endl;
            }
        } while (denominator == 0);
        reduce();
    }
    void output(){
        cout << numerator << "/" << denominator;
    }
};

void inputFraction(Fraction& frac) {
    frac.input();
}

void outputFraction(Fraction& frac) {
    frac.output();
}

int main() {
    Fraction frac1, frac2;  
    cout << "Enter the first fraction:\n";
    inputFraction(frac1);
    cout << "Enter the second fraction:\n";
    inputFraction(frac2);
    cout << "First fraction: ";
    outputFraction(frac1);
    cout << "Second fraction: ";
    outputFraction(frac2);
    Fraction sum = Fraction::add(frac1, frac2);
    cout << "Sum: ";
    outputFraction(sum);
    Fraction diff = Fraction::subtract(frac1, frac2);
    cout << "Difference: ";
    outputFraction(diff);
    Fraction prod = Fraction::multiply(frac1, frac2);
    cout << "Product: ";
    outputFraction(prod);
    Fraction quotient = Fraction::divide(frac1, frac2);
    cout << "Quotient: ";
    outputFraction(quotient);
    if (Fraction::isEqual(frac1, frac2)) {
        cout << "Fractions are equal.\n";
    } else {
        cout << "Fractions are not equal.\n";
    }
    cout << "First fraction as decimal: " << frac1.toDecimal() << endl;
    cout << "Second fraction as decimal: " << frac2.toDecimal() << endl;
}
