#include <iostream>
#include <string>

using namespace std;

class Car 
{
private:
    int regNumber;
    string model;      
    string owner;      
public:
    
    Car(int reg, string m, string o) : regNumber(reg), model(m), owner(o) {}
    Car(const Car& otherCar) 
    {
        regNumber = otherCar.regNumber; 
        model = otherCar.model;          
        owner = otherCar.owner;          
    }

    void setOwner(string newOwner) 
    {
        owner = newOwner;
    }

    void displayDetails() const 
    {
        cout << "Registration Number: " << regNumber << endl;
        cout << "Model: " << model << endl;
        cout << "Owner: " << owner << endl;
    }
};

int main() 
{
    Car car1(15234, "Ferrari", "Smith");
    cout << "Original Car Details: " << endl;
    car1.displayDetails();
    cout << "\nA new owner rents the car" << endl;
    
    Car car2 = car1;  
    car2.setOwner("Alex");  

    cout << "Copied Car Details :New Owner: " << endl;
    car2.displayDetails();
    cout << "\nOriginal Car Details after renting: " << endl;
    car1.displayDetails();
    return 0;
}
