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

        cout << "Type: " << type << "\n"
             << "ID: " << id << "\n"
             << "Name: " << name << "\n"
             << "Year (int): " << year << "\n"
             << "Extra Data: " << extraData << "\n"
             << "Certification: " << certification << "\n" << endl;
    }

    inputFile.close();
    return 0;
}
