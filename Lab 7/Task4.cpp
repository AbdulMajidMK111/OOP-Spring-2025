#include <iostream>
#include <vector>
#include <string>

class Person 
{
protected:
    std::string name, id, address, phoneNumber, email;

public:
    Person(std::string n, std::string i, std::string a, std::string p, std::string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    virtual void displayInfo() 
    {
        std::cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
                  << "\nPhone: " << phoneNumber << "\nEmail: " << email << "\n";
    }
    virtual void updateInfo(std::string newAddress, std::string newPhone, std::string newEmail) 
    {
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }
};

class Student : public Person 
{
    std::vector<std::string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(std::string n, std::string i, std::string a, std::string p, std::string e, int year, double gpa)
        : Person(n, i, a, p, e), enrollmentYear(year), GPA(gpa) {}
    void enrollCourse(std::string course) 
    {
        coursesEnrolled.push_back(course);
    }
    void displayInfo() override 
    {
        Person::displayInfo();
        std::cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << GPA << "\nCourses Enrolled: ";
        for (const auto &course : coursesEnrolled) std::cout << course << " ";
        std::cout << "\n";
    }
};

class Professor : public Person 
{
    std::string department;
    std::vector<std::string> coursesTaught;
    double salary;

public:
    Professor(std::string n, std::string i, std::string a, std::string p, std::string e, std::string dept, double sal)
        : Person(n, i, a, p, e), department(dept), salary(sal) {}
    void addCourse(std::string course) 
    {
        coursesTaught.push_back(course);
    }
    void displayInfo() override 
    {
        Person::displayInfo();
        std::cout << "Department: " << department << "\nSalary: " << salary << "\nCourses Taught: ";
        for (const auto &course : coursesTaught) std::cout << course << " ";
        std::cout << "\n";
    }
};

class Staff : public Person 
{
    std::string department, position;
    double salary;

public:
    Staff(std::string n, std::string i, std::string a, std::string p, std::string e, std::string dept, std::string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}
    void displayInfo() override 
    {
        Person::displayInfo();
        std::cout << "Department: " << department << "\nPosition: " << position << "\nSalary: " << salary << "\n";
    }
};

class Course 
{
    std::string courseId, courseName, instructor, schedule;
    int credits;
    std::vector<std::string> studentsEnrolled;

public:
    Course(std::string id, std::string name, int cr, std::string instr, std::string sched)
        : courseId(id), courseName(name), credits(cr), instructor(instr), schedule(sched) {}
    void registerStudent(std::string studentId) 
    {
        studentsEnrolled.push_back(studentId);
    }
    void displayCourseInfo() 
    {
        std::cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
                  << "\nCredits: " << credits << "\nInstructor: " << instructor
                  << "\nSchedule: " << schedule << "\nEnrolled Students: ";
        for (const auto &student : studentsEnrolled) std::cout << student << " ";
        std::cout << "\n";
    }
};

int main() 
{
    Student s1("Alice", "S1001", "123 Main St", "123-456-7890", "alice@example.com", 2022, 3.8);
    Professor p1("Dr. Smith", "P2001", "456 Elm St", "987-654-3210", "smith@university.com", "Computer Science", 90000);
    Staff st1("John Doe", "ST3001", "789 Oak St", "555-555-5555", "john@university.com", "Admin", "Clerk", 40000);
    Course c1("CS101", "Intro to Programming", 3, "Dr. Smith", "MWF 10:00-11:00");

    s1.enrollCourse("CS101");
    p1.addCourse("CS101");
    c1.registerStudent("S1001");

    std::cout << "\n--- Student Info ---\n";
    s1.displayInfo();

    std::cout << "\n--- Professor Info ---\n";
    p1.displayInfo();

    std::cout << "\n--- Staff Info ---\n";
    st1.displayInfo();

    std::cout << "\n--- Course Info ---\n";
    c1.displayCourseInfo();
    
    return 0;
}
