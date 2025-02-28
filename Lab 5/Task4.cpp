#include <iostream>
#include <string>

using namespace std;

class Battery 
{
private:
    int capacity;  
public:
    Battery(int cap) : capacity(cap) {}

    void displayBatteryDetails() const 
    {
        cout << "Battery Capacity: " << capacity << " mAh" << endl;
    }
};

class Smartphone 
{
private:
    string model;  
    Battery battery;  
public:
    Smartphone(string m, int batteryCapacity) : model(m), battery(batteryCapacity) {}
    void displayDetails() const 
    {
        cout << "Smartphone Model: " << model << endl;
        battery.displayBatteryDetails();  
    }
};

int main() 
{
    
    Smartphone smartphone1("i-phone", 4200);  
    smartphone1.displayDetails();
    cout << endl;
    Smartphone smartphone2("Samsung", 5000);  
    smartphone2.displayDetails();
    return 0;
}
