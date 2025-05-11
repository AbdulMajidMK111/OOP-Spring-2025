#include <iostream>
#include <exception>

using namespace std;

class StackOverflowException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack 
{
private:
    static const int capacity = 5;
    T data[capacity];
    int top;

public:
    Stack() : top(-1) {}

    void push(const T& item) 
    {
        if (top >= capacity - 1) 
        {
            throw StackOverflowException();
        }
        data[++top] = item;
    }

    T pop() 
    {
        if (top < 0) 
        {
            throw StackUnderflowException();
        }
        return data[top--];
    }

    bool isEmpty() const 
    {
        return top == -1;
    }

    bool isFull() const 
    {
        return top == capacity - 1;
    }
};

int main() 
{
    Stack<int> s;

    try 
    {
        for (int i = 0; i < 6; ++i) 
        {
            cout << "Pushing: " << i << endl;
            s.push(i);
        }
    } 
    catch (const StackOverflowException& e) 
    {
        cout << "Pushing to a full stack: " << e.what() << endl;
    }

    try 
    {
        for (int i = 0; i < 6; ++i) 
        {
            cout << "Popped: " << s.pop() << endl;
        }
    } 
    catch (const StackUnderflowException& e) 
    {
        cout << "Popping from an empty stack: " << e.what() << endl;
    }

    return 0;
}
