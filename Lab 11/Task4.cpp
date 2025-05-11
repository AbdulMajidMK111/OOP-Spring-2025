#include <iostream>
#include <exception>
#include <cmath>
#include <type_traits>
#include <string>

using namespace std;

class NegativeNumberException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

template <typename T>
typename enable_if<is_arithmetic<T>::value, double>::type
sqrtValue(T num) 
{
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(static_cast<double>(num));
}

template <typename T>
typename enable_if<!is_arithmetic<T>::value, double>::type
sqrtValue(T) 
{
    throw InvalidTypeException();
}

int main() 
{
    try 
    {
        cout << "sqrt(25): " << sqrtValue(25) << endl;
        cout << "sqrt(-4): ";
        cout << sqrtValue(-4) << endl;
    } 
    catch (const exception& e) 
    {
        cout << e.what() << endl;
    }

    try 
    {
        cout << "sqrt(\"hello\"): ";
        cout << sqrtValue(string("hello")) << endl;
    } 
    catch (const exception& e) 
    {
        cout << e.what() << endl;
    }

    return 0;
}
