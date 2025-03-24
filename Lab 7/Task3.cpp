#include <iostream>

class Currency 
{
protected:
    double amount;
    std::string currencyCode;
    std::string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, std::string code, std::string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double convertToBase() = 0;
    virtual double convertTo(Currency &targetCurrency)
    {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.exchangeRate;
    }
    virtual void displayCurrency() = 0;
};

class Dollar : public Currency 
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    double convertToBase() override 
    {
        return amount * exchangeRate;
    }
    void displayCurrency() override 
    {
        std::cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Euro : public Currency 
{
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}
    double convertToBase() override 
    {
        return amount * exchangeRate;
    }
    void displayCurrency() override 
    {
        std::cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Rupee : public Currency 
{
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}
    double convertToBase() override 
    {
        return amount * exchangeRate;
    }
    void displayCurrency() override 
    {
        std::cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

int main() 
{
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);
    
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();
    
    std::cout << "\nConverting 100 USD to EUR: " << usd.convertTo(eur) << " EUR\n";
    std::cout << "Converting 50 EUR to INR: " << eur.convertTo(inr) << " INR\n";
    std::cout << "Converting 5000 INR to USD: " << inr.convertTo(usd) << " USD\n";
    
    return 0;
}
