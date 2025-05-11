#include <iostream>
#include <exception>
#include <string>
#include <fstream>

using namespace std;

class FileException : public exception 
{
public:
    virtual const char* what() const noexcept override 
    {
        return "FileException - File error occurred.";
    }
};

class FileNotFoundException : public FileException 
{
public:
    const char* what() const noexcept override
    {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException 
{
public:
    const char* what() const noexcept override 
    {
        return "PermissionDeniedException - Access denied!";
    }
};

void readFile(const string& filename) 
{
    if (filename == "missing.txt") 
    {
        throw FileNotFoundException();
    } 
    else if (filename == "secret.txt") 
    {
        throw PermissionDeniedException();
    } 
    else 
    {
        cout << "Reading file: " << filename << endl;
    }
}

int main() 
{
    string files[] = { "missing.txt", "secret.txt", "notes.txt" };

    for (const auto& file : files) 
    {
        try 
        {
            readFile(file);
        } 
        catch (const FileNotFoundException& e) 
        {
            cout << "Reading '" << file << "': " << e.what() << endl;
        } 
        catch (const PermissionDeniedException& e) 
        {
            cout << "Reading '" << file << "': " << e.what() << endl;
        } 
        catch (const FileException& e) 
        {
            cout << "Reading '" << file << "': " << e.what() << endl;
        }
    }

    return 0;
}
