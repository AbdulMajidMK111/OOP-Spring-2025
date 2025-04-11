#include <iostream>

using namespace std;

class Humidity;

class Temperature 
{
private:
    float tempC;

public:
    Temperature(float t) : tempC(t) {}

    friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

class Humidity 
{
private:
    float humidityPercent;

public:
    Humidity(float h) : humidityPercent(h) {}

    friend float calculateHeatIndex(const Temperature&, const Humidity&);
};

float calculateHeatIndex(const Temperature& t, const Humidity& h) 
{
    float heatIndex = t.tempC + 0.1f * h.humidityPercent;
    return heatIndex;
}

int main() 
{
    Temperature temp(32.0f);   
    Humidity hum(70.0f);

    float heatIndex = calculateHeatIndex(temp, hum);
    cout << "Heat Index: " << heatIndex << "°C" << endl;

    return 0;
}
