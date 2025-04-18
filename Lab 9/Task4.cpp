#include <iostream>
#include <string>

using namespace std;

class PaymentMethod 
{
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod 
{
private:
    string cardNumber;

public:
    CreditCard(const string& cardNumber) : cardNumber(cardNumber) {}

    bool processPayment(double amount) override 
    {
        if (cardNumber.length() == 16) 
        {
            cout << "Credit Card payment of $" << amount << " processed successfully.\n";
            return true;
        } 
        else 
        {
            cout << "Credit Card payment failed: Invalid card number.\n";
            return false;
        }
    }
};

class DigitalWallet : public PaymentMethod
{
private:
    double balance;

public:
    DigitalWallet(double initialBalance) : balance(initialBalance) {}

    bool processPayment(double amount) override 
    {
        if (amount <= balance) 
        {
            balance -= amount;
            cout << "Digital Wallet payment of $" << amount << " successful. Remaining balance: $" << balance << endl;
            return true;
        } 
        else 
        {
            cout << "Digital Wallet payment failed: Insufficient balance.\n";
            return false;
        }
    }
};

int main() 
{
    CreditCard myCard("1234567812345678");
    DigitalWallet myWallet(100.00);

    PaymentMethod* payment1 = &myCard;
    PaymentMethod* payment2 = &myWallet;

    cout << "Processing Payments\n";
    payment1->processPayment(50.00);
    payment2->processPayment(30.00);
    payment2->processPayment(80.00);

    return 0;
}
