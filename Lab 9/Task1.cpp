#include <iostream>

using namespace std;

class Vehicle 
{
protected:
    string model;
    double rate;

public:
    Vehicle(const string& model, double rate) : model(model), rate(rate) {}

    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0; 
    virtual ~Vehicle() {} 
};

class Car : public Vehicle 
{
public:
    Car(const string& model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() const override 
    {
        return rate;
    }

    void displayDetails() const override 
    {
        cout << "Car Model: " << model << "\nDaily Rate: $" << getDailyRate() << endl;
    }
};

class Bike : public Vehicle 
{
public:
    Bike(const string& model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() const override 
    {
        return rate;
    }

    void displayDetails() const override 
    {
        cout << "Bike Model: " << model << "\nDaily Rate: $" << getDailyRate() << endl;
    }
};

int main() 
{
    Car car1("Honda Civic", 70.0);
    Bike bike1("Suzuki Gixxer", 30.0);

    Vehicle* v1 = &car1;
    Vehicle* v2 = &bike1;

    v1->displayDetails();
    v2->displayDetails();
    return 0;
}
