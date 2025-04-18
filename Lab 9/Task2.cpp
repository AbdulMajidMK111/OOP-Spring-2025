#include <iostream>

using namespace std;

class SmartDevice 
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice 
{
private:
    bool isOn;
    int brightness; 

public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn() override 
    {
        isOn = true;
        brightness = 100;
        cout << "LightBulb turned on.\n";
    }

    void turnOff() override 
    {
        isOn = false;
        brightness = 0;
        cout << "LightBulb turned off.\n";
    }

    void getStatus() const override 
    {
        cout << "LightBulb is " << (isOn ? "ON" : "OFF");
        if (isOn)
            cout << " Brightness: " << brightness << "%";
        cout << endl;
    }
};

class Thermostat : public SmartDevice 
{
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(22.0) {} 

    void turnOn() override 
    {
        isOn = true;
        cout << "Thermostat turned on.\n";
    }

    void turnOff() override 
    {
        isOn = false;
        cout << "Thermostat turned off.\n";
    }

    void getStatus() const override 
    {
        cout << "Thermostat is " << (isOn ? "ON" : "OFF");
        if (isOn)
            cout << " Temperature: " << temperature << "°C";
        cout << endl;
    }
};

int main() 
{
    LightBulb bulb;
    Thermostat thermo;

    SmartDevice* devices[2];
    devices[0] = &bulb;
    devices[1] = &thermo;

    cout << "Turning Devices On\n";
    devices[0]->turnOn();
    devices[1]->turnOn();

    cout << "\nDevice Statuses\n";
    devices[0]->getStatus();
    devices[1]->getStatus();

    cout << "\nTurning Devices Off\n";
    devices[0]->turnOff();
    devices[1]->turnOff();

    cout << "\nDevice Statuses\n";
    devices[0]->getStatus();
    devices[1]->getStatus();

    return 0;
}
