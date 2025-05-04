#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    {
        ofstream outFile("config.txt");
        outFile << "AAAAABBBBBCCCCC";
        outFile.close();
    }

    fstream file("config.txt", ios::in | ios::out);
    if (!file) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    file.seekp(5);
    file << "XXXXX";
    file.close();

    ifstream inFile("config.txt");
    string content;
    getline(inFile, content);
    cout << "Updated content: " << content << endl;
    inFile.close();

    return 0;
}
