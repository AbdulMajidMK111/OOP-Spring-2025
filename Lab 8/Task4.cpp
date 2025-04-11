#include <iostream>

using namespace std;

class Currency 
{
private:
    double amount;

public:
    Currency(double amt = 0.0) : amount(amt) {}

    Currency operator+(const Currency& other) const 
    {
        return Currency(amount + other.amount);
    }

    Currency operator-(const Currency& other) const 
    {
        return Currency(amount - other.amount);
    }

    Currency operator-() const 
    {
        return Currency(-amount);
    }

    Currency& operator+=(const Currency& other) 
    {
        amount += other.amount;
        return *this;
    }

    Currency& operator-=(const Currency& other)
    {
        amount -= other.amount;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Currency& c) 
    {
        os << "$" << c.amount;
        return os;
    }
};

int main() 
{
    Currency price1(49.99), price2(20.00);
    Currency total = price1 + price2;
    Currency discount(5.00);

    cout << "Price 1: " << price1 << endl;
    cout << "Price 2: " << price2 << endl;
    cout << "Total: " << total << endl;

    total -= discount;
    cout << "After Discount: " << total << endl;

    Currency refund = -price1;
    cout << "Refund (Negated Price 1): " << refund << endl;

    Currency fee(2.50);
    total += fee;
    cout << "After Adding Fee: " << total << endl;

    return 0;
}
