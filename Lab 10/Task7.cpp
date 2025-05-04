#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ofstream outputFile("sensor_log.txt");

    if (!outputFile) 
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outputFile << "Sensor 1: Temperature = 22.5C" << endl;
    streampos pos1 = outputFile.tellp();
    cout << "Position after first write: " << pos1 << endl;

    outputFile << "Sensor 2: Pressure = 1013 hPa" << endl;
    streampos pos2 = outputFile.tellp();
    cout << "Position after second write: " << pos2 << endl;

    outputFile << "Sensor 3: Humidity = 45%" << endl;
    streampos pos3 = outputFile.tellp();
    cout << "Position after third write: " << pos3 << endl;

    outputFile.close();
    return 0;
}
