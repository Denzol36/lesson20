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
    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }
    void input();
    void output();
    double toDecimal();
};

void Fraction::input() {
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

void Fraction::output() {
    cout << numerator << "/" << denominator << endl;
}

double Fraction::toDecimal() {
    return (double)numerator / denominator;
}

Fraction add(Fraction& frac1, Fraction& frac2) {
    int num = frac1.getNumerator() * frac2.getDenominator() + frac2.getNumerator() * frac1.getDenominator();
    int denom = frac1.getDenominator() * frac2.getDenominator();
    return Fraction(num, denom);
}

Fraction subtract(Fraction& frac1, Fraction& frac2) {
    int num = frac1.getNumerator() * frac2.getDenominator() - frac2.getNumerator() * frac1.getDenominator();
    int denom = frac1.getDenominator() * frac2.getDenominator();
    return Fraction(num, denom);
}

Fraction multiply(Fraction& frac1, Fraction& frac2) {
    int num = frac1.getNumerator() * frac2.getNumerator();
    int denom = frac1.getDenominator() * frac2.getDenominator();
    return Fraction(num, denom);
}

Fraction divide(Fraction& frac1, Fraction& frac2) {
    if (frac2.getNumerator() == 0) {
        cout << "Error: Division by zero!" << endl;
        return frac1;
    }
    int num = frac1.getNumerator() * frac2.getDenominator();
    int denom = frac1.getDenominator() * frac2.getNumerator();
    return Fraction(num, denom);
}

bool isEqual(Fraction& frac1, Fraction& frac2) {
    return frac1.getNumerator() == frac2.getNumerator() && frac1.getDenominator() == frac2.getDenominator();
}

int main() {
    Fraction frac1, frac2;
    cout << "Enter the first fraction:\n";
    frac1.input();
    cout << "Enter the second fraction:\n";
    frac2.input();
    
    cout << "First fraction: ";
    frac1.output();
    cout << "Second fraction: ";
    frac2.output();
    
    Fraction sum = add(frac1, frac2);
    cout << "Sum: ";
    sum.output();
    
    Fraction diff = subtract(frac1, frac2);
    cout << "Difference: ";
    diff.output();
    
    Fraction prod = multiply(frac1, frac2);
    cout << "Product: ";
    prod.output();
    
    Fraction quotient = divide(frac1, frac2);
    cout << "Quotient: ";
    quotient.output();
    
    if (isEqual(frac1, frac2)) {
        cout << "Fractions are equal.\n";
    } else {
        cout << "Fractions are not equal.\n";
    }
    
    cout << "First fraction as decimal: " << frac1.toDecimal() << endl;
    cout << "Second fraction as decimal: " << frac2.toDecimal() << endl;
}