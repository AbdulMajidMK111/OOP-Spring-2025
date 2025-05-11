#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;

class InsufficientFundsException : public exception 
{
private:
    string message;
public:
    InsufficientFundsException(double deficit) 
    {
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "InsufficientFundsException - Deficit: $" << deficit;
        message = ss.str();
    }

    const char* what() const noexcept override 
    {
        return message.c_str();
    }
};

template <typename T>
class BankAccount 
{
private:
    T balance;
public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    void withdraw(T amount) 
    {
        if (amount > balance) 
        {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
        cout << "Withdrawn: $" << fixed << setprecision(2) << static_cast<double>(amount) << endl;
    }

    void displayBalance() const 
    {
        cout << "Balance: $" << fixed << setprecision(2) << static_cast<double>(balance) << endl;
    }
};

int main() 
{
    BankAccount<double> account(500.0);

    account.displayBalance();

    try 
    {
        account.withdraw(600.0);
    } 
    catch (const InsufficientFundsException& e) 
    {
        cout << e.what() << endl;
    }

    return 0;
}
