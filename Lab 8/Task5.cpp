#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

class Fraction 
{
private:
    int numerator;
    int denominator;

    void simplify() 
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) 
    {
        if (den == 0) 
        {
            cout << "Error: Denominator cannot be zero!" << endl;
            exit(1);
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    Fraction operator+(const Fraction& other) const 
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) const 
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) 
    {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

int main() 
{
    Fraction f1(3, 4);
    Fraction f2(2, 5); 

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "\nAddition:      f1 + f2 = " << (f1 + f2) << endl;
    cout << "Subtraction:   f1 - f2 = " << (f1 - f2) << endl;
    cout << "Multiplication: f1 * f2 = " << (f1 * f2) << endl;
    cout << "Division:      f1 / f2 = " << (f1 / f2) << endl;

    return 0;
}
