#include <iostream>
#include <string>

using namespace std;

class Teacher; 
float calculateAverageGrade(const class Student&);

class Student 
{
private:
    string name;
    float grades[3];

public:
    Student(string n, float g1, float g2, float g3) 
    {
        name = n;
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }
    friend class Teacher;
    friend float calculateAverageGrade(const Student&);
};

class Teacher 
{
public:
    void displayGrades(const Student& s) 
    {
        cout << "Grades for " << s.name << ": ";
        for (int i = 0; i < 3; ++i) 
        {
            cout << s.grades[i] << " ";
        }
        cout << endl;
    }

    void updateGrade(Student& s, int index, float newGrade) 
    {
        if (index >= 0 && index < 3) 
        {
            s.grades[index] = newGrade;
        }
    }
};

float calculateAverageGrade(const Student& s) 
{
    float sum = 0;
    for (int i = 0; i < 3; ++i) 
    {
        sum += s.grades[i];
    }
    return sum / 3.0f;
}

int main()
{
    Student s1("Alice", 85.0f, 90.0f, 88.0f);
    Teacher t1;

    cout << "Initial Grades:\n";
    t1.displayGrades(s1);
    cout << "Initial Average: " << calculateAverageGrade(s1) << endl;

    t1.updateGrade(s1, 1, 95.0f);

    cout << "\nAfter Updating Grade:\n";
    t1.displayGrades(s1);
    cout << "Updated Average: " << calculateAverageGrade(s1) << endl;

    return 0;
}
