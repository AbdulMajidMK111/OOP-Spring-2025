#include <iostream>
#include <vector>

class Shape 
{
protected:
    std::string color;
    double posX, posY;
    double borderThickness;

public:
    Shape(double x, double y, std::string col, double border = 1.0)
        : posX(x), posY(y), color(col), borderThickness(border) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape 
{
    double radius;

public:
    Circle(double x, double y, double r, std::string col, double border = 1.0)
        : Shape(x, y, col, border), radius(r) {}
    void draw() override 
    {
        std::cout << "Drawing Circle at (" << posX << ", " << posY << ") with radius " << radius << " and color " << color << "\n";
    }
    double calculateArea() override 
    {
        return 3.14159 * radius * radius;
    }
    double calculatePerimeter() override 
    {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape 
{
    double width, height;

public:
    Rectangle(double x, double y, double w, double h, std::string col, double border = 1.0)
        : Shape(x, y, col, border), width(w), height(h) {}
    void draw() override 
    {
        std::cout << "Drawing Rectangle at (" << posX << ", " << posY << ") with width " << width << " and height " << height << " and color " << color << "\n";
    }
    double calculateArea() override 
    {
        return width * height;
    }
    double calculatePerimeter() override 
    {
        return 2 * (width + height);
    }
};

class Triangle : public Shape 
{
    double sideA, sideB, sideC;

public:
    Triangle(double x, double y, double a, double b, double c, std::string col, double border = 1.0)
        : Shape(x, y, col, border), sideA(a), sideB(b), sideC(c) {}
    void draw() override 
    {
        std::cout << "Drawing Triangle at (" << posX << ", " << posY << ") with sides " << sideA << ", " << sideB << ", " << sideC << " and color " << color << "\n";
    }
    double calculateArea() override 
    {
        double s = (sideA + sideB + sideC) / 2;
        double area = s * (s - sideA) * (s - sideB) * (s - sideC);
        double approxSqrt = area;
        for (int i = 0; i < 10; ++i) approxSqrt = 0.5 * (approxSqrt + area / approxSqrt);
        return approxSqrt;
    }
    double calculatePerimeter() override 
    {
        return sideA + sideB + sideC;
    }
};

int main() 
{
    Circle c(10, 10, 5, "Red");
    Rectangle r(0, 0, 10, 20, "Blue");
    Triangle t(5, 5, 3, 4, 5, "Green");
    
    c.draw();
    std::cout << "Circle Area: " << c.calculateArea() << " Perimeter: " << c.calculatePerimeter() << "\n";
    
    r.draw();
    std::cout << "Rectangle Area: " << r.calculateArea() << " Perimeter: " << r.calculatePerimeter() << "\n";
    
    t.draw();
    std::cout << "Triangle Area: " << t.calculateArea() << " Perimeter: " << t.calculatePerimeter() << "\n";
    
    return 0;
}
