#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book 
{
private:
    string title;
    string author;
    string ISBN;

public:
    Book(const string& title, const string& author, const string& ISBN);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
};

#endif 
