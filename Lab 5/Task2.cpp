#include <iostream>
#include <string>

using namespace std;

class Patient 
{
private:
    int patientID;       
    string name;      
    double* testResults;
    int numResults;     

public:
    Patient(int id, string n, double* results, int num) : patientID(id), name(n), numResults(num) 
    {
        testResults = new double[numResults]; 
        for (int i = 0; i < numResults; i++) 
        {
            testResults[i] = results[i];  
        }
    }
 
    Patient(const Patient& other) 
    {
        patientID = other.patientID;
        name = other.name;
        numResults = other.numResults; 
        testResults = new double[numResults];
        for (int i = 0; i < numResults; i++) 
        {
            testResults[i] = other.testResults[i];
        }
    }   
    ~Patient() 
    {
        delete[] testResults;  
    }

    void displayDetails() const 
    {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Test Results: ";
        for (int i = 0; i < numResults; i++) 
        {
            cout << testResults[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{   
    double results1[] = {88.9, 73.1, 99.5, 84.1};   
    Patient patient1(12073, "Jason", results1, 4);
    cout << "Original Patient Details: " << endl;
    patient1.displayDetails();
    cout << endl;

    Patient patient2 = patient1; 
    double results2[] = {79.4, 99.3, 80.9, 91.8};
    
    Patient patient3(19232, "Stokes", results2, 4); 
    cout << "Copied Patient Details (New): " << endl;
    patient2.displayDetails();
    cout << endl;    
    cout << "Original Patient Details after copying: " << endl;
    patient1.displayDetails();
    cout << endl;

    cout << "Another Patient Details: " << endl;
    patient3.displayDetails();
    return 0;
}
