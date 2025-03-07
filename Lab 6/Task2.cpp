#include <iostream>
using namespace std;

class Vehicle 
{
 public:
  string brand;
  int speed;

  Vehicle() {
    brand = "Unknown";
    speed = 0;
  }

  Vehicle(string b, int s) {
    brand = b;
    speed = s;
  }

  virtual void displayDetails() {
    cout << "Brand: " << brand << endl;
    cout << "Speed: " << speed << " km/h" << endl;
  }
};

class Car : public Vehicle {
 public:
  int seats;

  Car(string b, int s, int se) : Vehicle(b, s) { seats = se; }

  void displayDetails() override {
    Vehicle::displayDetails();
    cout << "Seats: " << seats << endl;
  }
};

class ElectricCar : public Car {
 public:
  int batteryLife;

  ElectricCar(string b, int s, int se, int bL) : Car(b, s, se) {
    batteryLife = bL;
  }

  void displayDetails() override {
    Car::displayDetails();
    cout << "Battery Life: " << batteryLife << " hours" << endl;
  }
};

int main() {
  string brand;
  int speed, seats, batteryLife;

  cout << "Enter Electric Car Details:" << endl;
  cout << "Brand: ";
  getline(cin, brand);
  cout << "Speed: ";
  cin >> speed;
  cout << "Seats: ";
  cin >> seats;
  cout << "Battery Life: ";
  cin >> batteryLife;

  ElectricCar electricCar(brand, speed, seats, batteryLife);
  electricCar.displayDetails();

  return 0;
}
