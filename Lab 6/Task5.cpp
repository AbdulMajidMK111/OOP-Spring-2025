#include <iostream>

using namespace std;

class Device 
{
protected:
    int deviceID;
    bool status;
public:
    Device(int id, bool stat) : deviceID(id), status(stat) {}
    virtual void displayDetails() 
    {
        cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") << endl;
    }
};

class SmartPhone : virtual public Device 
{
protected:
    float screenSize;
public:
    SmartPhone(int id, bool stat, float size) : Device(id, stat), screenSize(size) {}
    void displayDetails() override 
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device 
{
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int id, bool stat, bool hrMonitor) : Device(id, stat), heartRateMonitor(hrMonitor) {}
    void displayDetails() override 
    {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch 
{
private:
    int stepCounter;
public:
    SmartWearable(int id, bool stat, float size, bool hrMonitor, int steps) 
        : Device(id, stat), SmartPhone(id, stat, size), SmartWatch(id, stat, hrMonitor), stepCounter(steps) {}
    void displayDetails() override 
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << "\nHeart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << "\nStep Counter: " << stepCounter << endl;
    }
};

int main() 
{
    int deviceID, stepCounter;
    bool status, heartRateMonitor;
    float screenSize;
    
    cout << "Enter Device ID: ";
    cin >> deviceID;
    cout << "Enter Status (1 for On, 0 for Off): ";
    cin >> status;

    cout << "Enter Screen Size (in inches): ";
    cin >> screenSize;
    cout << "Does it have a Heart Rate Monitor? (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;

    cout << "Enter Step Counter Value: ";
    cin >> stepCounter;
    
    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    
    cout << "\nSmart Wearable Details:\n";
    wearable.displayDetails();    
    return 0;
}
