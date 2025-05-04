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
        string type, id, name, year, extraData, certification;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');

        auto trim = [](string& s) 
        {
            size_t start = s.find_first_not_of(" ");
            size_t end = s.find_last_not_of(" ");
            s = (start == string::npos) ? "" : s.substr(start, end - start + 1);
        };

        trim(type);
        trim(id);
        trim(name);
        trim(year);
        trim(extraData);
        trim(certification);

        cout << "Type: " << type << "\n"
             << "ID: " << id << "\n"
             << "Name: " << name << "\n"
             << "Year: " << year << "\n"
             << "Extra Data: " << extraData << "\n"
             << "Certification: " << certification << "\n" << endl;
    }

    inputFile.close();
    return 0;
}
