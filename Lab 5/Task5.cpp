#include <iostream>
#include <string>

using namespace std;

class TourGuide 
{
private:
    string name;          
    int Experience; 
    string specialization; 
public:
    TourGuide(string n, int experience, string spec) 
        : name(n), Experience(experience), specialization(spec) {}
   
    void displayDetails() const 
    {
        cout << "Tour Guide Name: " << name << endl;
        cout << "Years of Experience: " << Experience << " years" << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class TravelAgency 
{
private:
    TourGuide** tourGuides; 
    int totalGuides;       
    int capacity;         
public:
    TravelAgency(int cap) : totalGuides(0), capacity(cap) 
    {
        tourGuides = new TourGuide*[capacity];
    }
    ~TravelAgency() 
    {
        for (int i = 0; i < totalGuides; i++) 
        {
            delete tourGuides[i];  
        }
        delete[] tourGuides;  
    }

    void addTourGuide(const string& name, int experience, const string& specialization) 
    {
        if (totalGuides < capacity) 
        {
            tourGuides[totalGuides] = new TourGuide(name, experience, specialization); 
            totalGuides++;
        } 
        else 
        {
            cout << "No more space to add a new tour guide. Capacity reached!" << endl;
        }
    }

    void displayAgencyDetails() const
    {
        cout << "Travel Agency Details:" << endl;
        cout << "Total Guides: " << totalGuides << endl;
        for (int i = 0; i < totalGuides; i++) 
        {
            cout << "Guide " << (i + 1) << " details:" << endl;
            tourGuides[i]->displayDetails();
        }
    }
};

int main() 
{
    TravelAgency agency(2);
    agency.addTourGuide("Smith", 4, "Linguistic");
    agency.addTourGuide("Alex", 9, "History");
    agency.addTourGuide("Jason", 7, "Nature");
    agency.displayAgencyDetails();
    return 0;
}
