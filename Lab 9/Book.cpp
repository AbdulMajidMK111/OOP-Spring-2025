#include "Book.h"

Book::Book(const string& title, const string& author, const string& ISBN)
    : title(title), author(author), ISBN(ISBN) {}

string Book::getTitle() const 
{
    return title;
}

string Book::getAuthor() const 
{
    return author;
}

string Book::getISBN() const 
{
    return ISBN;
}
