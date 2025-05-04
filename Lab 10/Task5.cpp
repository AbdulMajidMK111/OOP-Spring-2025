#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() 
{
    ifstream inputFile("vehicles.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error: Could not open the file 'vehicles.txt'" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) 
    {
        if (line.empty() || line[0] == '#')
            continue;

        istringstream ss(line);
        string type, id, name, yearStr, extraData, certification;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, yearStr, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');

        int year = stoi(yearStr);

        float softwareVersion = 0.0;
        int batteryCapacity = 0;
        int cargo = 0;

        if (type == "AutonomousCar") 
        {
            size_t pos = extraData.find(":");
            if (pos != string::npos) 
            {
                string versionStr = extraData.substr(pos + 2);
                softwareVersion = stof(versionStr);
                cout << "Software Version (AutonomousCar): " << softwareVersion << endl;
            }
        } 
        else if (type == "ElectricVehicle") 
        {
            size_t pos = extraData.find(":");
            if (pos != string::npos) 
            {
                string batteryStr = extraData.substr(pos + 2);
                batteryCapacity = stoi(batteryStr);
                cout << "Battery Capacity (ElectricVehicle): " << batteryCapacity << endl;
            }
        } 
        else if (type == "HybridTruck") 
        {
            size_t pos1 = extraData.find(":");
            size_t pos2 = extraData.find("|");

            if (pos1 != string::npos && pos2 != string::npos) 
            {
                string cargoStr = extraData.substr(pos1 + 2, pos2 - pos1 - 3);
                cargo = stoi(cargoStr);

                string batteryStr = extraData.substr(pos2 + 2);
                batteryCapacity = stoi(batteryStr);

                cout << "Cargo Capacity (HybridTruck): " << cargo << endl;
                cout << "Battery Capacity (HybridTruck): " << batteryCapacity << endl;
            }
        } 
        else 
        {
            cerr << "Error: Unknown vehicle type '" << type << "'!" << endl;
        }

        cout << "ID: " << id << "\n"
             << "Year (int): " << year << "\n"
             << "Extra Data: " << extraData << "\n"
             << "Certification: " << certification << "\n" << endl;
    }

    inputFile.close();
    return 0;
}
