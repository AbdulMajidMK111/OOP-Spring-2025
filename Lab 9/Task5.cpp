#include <iostream>

using namespace std;

class Activity 
{
public:
    virtual double calculateCaloriesBurned() const = 0;
    virtual ~Activity() {}
};

class Running : public Activity 
{
private:
    double distance;
    double time;

public:
    Running(double distance, double time) : distance(distance), time(time) {}

    double calculateCaloriesBurned() const override 
    {
        double MET = 9.8;
        double weight = 70;
        return 0.0175 * MET * weight * time;
    }
};

class Cycling : public Activity 
{
private:
    double speed;
    double time;

public:
    Cycling(double speed, double time) : speed(speed), time(time) {}

    double calculateCaloriesBurned() const override 
    {
        double MET = (speed < 16) ? 4.0 : (speed < 20) ? 6.8 : 8.0;
        double weight = 70;
        double minutes = time * 60;
        return 0.0175 * MET * weight * minutes;
    }
};

int main() 
{
    Running run(5.0, 30.0);
    Cycling cycle(18.0, 1.0);

    Activity* a1 = &run;
    Activity* a2 = &cycle;

    cout << "Calories burned while running: " << a1->calculateCaloriesBurned() << " kcal\n";
    cout << "Calories burned while cycling: " << a2->calculateCaloriesBurned() << " kcal\n";

    return 0;
}
