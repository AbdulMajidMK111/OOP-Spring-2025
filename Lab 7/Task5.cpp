#include <iostream>
#include <vector>
#include <string>

class Media 
{
protected:
    std::string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(std::string t, std::string pDate, std::string id, std::string pub)
        : title(t), publicationDate(pDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}
    virtual void displayInfo() 
    {
        std::cout << "Title: " << title << "\nPublication Date: " << publicationDate
                  << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
                  << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << "\n";
    }
    void checkOut() 
    {
        if (!isCheckedOut) 
        {
            isCheckedOut = true;
            std::cout << title << " has been checked out.\n";
        } 
        else 
        {
            std::cout << title << " is already checked out.\n";
        }
    }
    void returnItem() 
    {
        if (isCheckedOut) 
        {
            isCheckedOut = false;
            std::cout << title << " has been returned.\n";
        } 
        else 
        {
            std::cout << title << " was not checked out.\n";
        }
    }
};

class Book : public Media 
{
    std::string author, ISBN;
    int numberOfPages;

public:
    Book(std::string t, std::string pDate, std::string id, std::string pub, std::string auth, std::string isbn, int pages)
        : Media(t, pDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override 
    {
        Media::displayInfo();
        std::cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << "\n";
    }
};

class DVD : public Media 
{
    std::string director, rating;
    double duration;

public:
    DVD(std::string t, std::string pDate, std::string id, std::string pub, std::string dir, double dur, std::string rate)
        : Media(t, pDate, id, pub), director(dir), duration(dur), rating(rate) {}
    void displayInfo() override 
    {
        Media::displayInfo();
        std::cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << "\n";
    }
};

class CD : public Media 
{
    std::string artist, genre;
    int numberOfTracks;

public:
    CD(std::string t, std::string pDate, std::string id, std::string pub, std::string art, int tracks, std::string gen)
        : Media(t, pDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}
    void displayInfo() override 
    {
        Media::displayInfo();
        std::cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << "\n";
    }
};

class Magazine : public Media 
{
    int issueNumber;

public:
    Magazine(std::string t, std::string pDate, std::string id, std::string pub, int issue)
        : Media(t, pDate, id, pub), issueNumber(issue) {}
    void displayInfo() override 
    {
        Media::displayInfo();
        std::cout << "Issue Number: " << issueNumber << "\n";
    }
};

int main() 
{
    Book b1("The Great Gatsby", "1925", "B1001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD d1("Inception", "2010", "D2001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c1("Thriller", "1982", "C3001", "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine m1("National Geographic", "2023", "M4001", "NatGeo", 150);

    std::cout << "\n--- Media Collection ---\n";
    b1.displayInfo();
    d1.displayInfo();
    c1.displayInfo();
    m1.displayInfo();

    std::cout << "\n--- Checking Out Items ---\n";
    b1.checkOut();
    d1.checkOut();
    c1.checkOut();

    std::cout << "\n--- Returning Items ---\n";
    b1.returnItem();
    d1.returnItem();
    c1.returnItem();

    return 0;
}
