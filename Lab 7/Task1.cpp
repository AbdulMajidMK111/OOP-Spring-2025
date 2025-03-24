#include <iostream>
#include <vector>

class Account 
{
protected:
    std::string accountHolderName;
    int accountNumber;
    double balance;
    std::string accountType;
    std::vector<std::string> transactions;

public:
    Account(std::string name, int number, double initialBalance, std::string type = "General")
        : accountHolderName(name), accountNumber(number), balance(initialBalance), accountType(type) {}
    virtual void deposit(double amount) 
    {
        balance += amount;
        transactions.push_back("Deposited: " + std::to_string(amount));
    }
    
    virtual void withdraw(double amount) 
    {
        if (amount > balance) 
        {
            std::cout << "Insufficient funds.\n";
            return;
        }
        balance -= amount;
        transactions.push_back("Withdrawn: " + std::to_string(amount));
    }
    virtual void calculateInterest() = 0;
    
    virtual void printStatement() 
    {
        std::cout << "Statement for Account: " << accountNumber << "\n";
        for (const auto& t : transactions) std::cout << t << "\n";
        std::cout << "Current Balance: " << balance << "\n";
    }
    void getAccountInfo() 
    {
        std::cout << "Account Holder: " << accountHolderName << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << "\nType: " << accountType << "\n";
    }
};

class SavingsAccount : public Account 
{
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(std::string name, int number, double initialBalance, double rate, double minBal)
        : Account(name, number, initialBalance, "Savings"), interestRate(rate), minimumBalance(minBal) {}
    void calculateInterest() override 
    {
        double interest = balance * (interestRate / 100);
        balance += interest;
        transactions.push_back("Interest Added: " + std::to_string(interest));
    }
    
    void withdraw(double amount) override 
    {
        if (balance - amount < minimumBalance) 
        {
            std::cout << "Cannot withdraw. Minimum balance required: " << minimumBalance << "\n";
            return;
        }
        Account::withdraw(amount);
    }
};

class CheckingAccount : public Account 
{
public:
    CheckingAccount(std::string name, int number, double initialBalance)
        : Account(name, number, initialBalance, "Checking") {}
    void calculateInterest() override {}
};

class FixedDepositAccount : public Account 
{
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(std::string name, int number, double initialBalance, double rate, int maturity)
        : Account(name, number, initialBalance, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}
    void calculateInterest() override 
    {
        double interest = balance * (fixedInterestRate / 100);
        balance += interest;
        transactions.push_back("Fixed Deposit Interest Added: " + std::to_string(interest));
    }
    
    void withdraw(double amount) override 
    {
        std::cout << "Withdrawals are not allowed before maturity.\n";
    }
};

int main() 
{
    SavingsAccount sa("John Doe", 1001, 5000, 5, 1000);
    CheckingAccount ca("Jane Smith", 1002, 3000);
    FixedDepositAccount fda("Alice Brown", 1003, 10000, 7, 12);
    
    sa.deposit(1000);
    sa.withdraw(2000);
    sa.calculateInterest();
    sa.printStatement();

    ca.deposit(500);
    ca.withdraw(1000);
    ca.printStatement();

    fda.calculateInterest();
    fda.withdraw(2000);
    fda.printStatement();

    return 0;
}
