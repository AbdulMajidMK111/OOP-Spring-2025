#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct InventoryItem 
{
    int itemID;
    char itemName[20];  

    InventoryItem(int id = 0, const char* name = "") 
    {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName) - 1);  
        itemName[sizeof(itemName) - 1] = '\0';  
    }
};

int main() 
{
    InventoryItem item1(101, "Gadget"); 

    ofstream outputFile("inventory.dat", ios::binary);
    if (!outputFile) 
    {
        cerr << "Error: Could not open the file 'inventory.dat' for writing." << endl;
        return 1;
    }

    outputFile.write(reinterpret_cast<char*>(&item1), sizeof(item1)); 
    outputFile.close(); 

    InventoryItem item2;  

    ifstream inputFile("inventory.dat", ios::binary);
    if (!inputFile) 
    {
        cerr << "Error: Could not open the file 'inventory.dat' for reading." << endl;
        return 1;
    }

    inputFile.read(reinterpret_cast<char*>(&item2), sizeof(item2));
    inputFile.close();  

    cout << "Loaded Item ID: " << item2.itemID << endl;
    cout << "Loaded Item Name: " << item2.itemName << endl;

    return 0;
}
