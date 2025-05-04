#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ifstream inFile("data_records.txt", ios::binary); 

    if (!inFile.is_open()) 
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    const int BYTES_PER_LINE = 10; 

    inFile.seekg(2 * BYTES_PER_LINE, ios::beg); 

    string record;
    getline(inFile, record);

    cout << record << endl;

    inFile.close();
    return 0;
}
