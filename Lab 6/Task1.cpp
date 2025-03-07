#include <iostream>
using namespace std;

class Employee {
 public:
  string name;
  float salary;

  Employee() {
    name = "X";
    salary = 0.0;
  }

  Employee(string n, float s) {
    name = n;
    salary = s;
  }

  virtual void displayDetails() {
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
  }
};

class Manager : public Employee {
 public:
  float bonus;

  Manager(string n, float s, float b) : Employee(n, s) { bonus = b; }

  void displayDetails() override {
    Employee::displayDetails();
    cout << "Bonus: " << bonus << endl;
  }
};

int main() {
  string name;
  float salary, bonus;

  cout << "Enter Manager's Name: ";
  getline(cin, name);
  cout << "Enter Manager's Salary: ";
  cin >> salary;
  cout << "Enter Manager's Bonus: ";
  cin >> bonus;

  Manager manager(name, salary, bonus);

  manager.displayDetails();

  return 0;
}
