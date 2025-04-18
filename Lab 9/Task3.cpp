#include <iostream>
#include "Book.h"

using namespace std;

int main() 
{
    Book myBook("1984", "George Orwell", "9780451524935");

    cout << "Book Title : " << myBook.getTitle() << endl;
    cout << "Author : " << myBook.getAuthor() << endl;
    cout << "ISBN : " << myBook.getISBN() << endl;

    return 0;
}
