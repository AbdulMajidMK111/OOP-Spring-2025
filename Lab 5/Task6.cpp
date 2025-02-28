#include <iostream>
#include <string>

using namespace std;

class Movie 
{
private:
    string title;
    string director;
    int duration; 
public:
    Movie(const string& t, const string& d, int dur)
        : title(t), director(d), duration(dur) {}

    void displayDetails() const 
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

class CinemaHall 
{
private:
    string hallName;
    Movie** movies;
    int movieCount;  

public:
    CinemaHall(const string& name, int count)
        : hallName(name), movieCount(count) 
    {
        movies = new Movie*[movieCount];
    }

    ~CinemaHall() 
    {
        for (int i = 0; i < movieCount; ++i) 
        {
            delete movies[i];
        }
        delete[] movies;
    }

    void addMovie(int index, const string& title, const string& director, int duration) 
    {
        if (index >= 0 && index < movieCount) 
        {
            movies[index] = new Movie(title, director, duration);
        }
    }

    void displayCinemaDetails() const 
    {
        cout << "Cinema Hall: " << hallName << endl;
        cout << "Currently Screening Movies: " << endl;
        if (movieCount == 0) 
        {
            cout << "No movies are being screened currently." << endl;
        } 
        else 
        {
            for (int i = 0; i < movieCount; ++i) 
            {
                movies[i]->displayDetails();
                cout << "\n";
            }
        }
    }
};

int main() 
{
    CinemaHall cinema("Cineplex", 3);
    cinema.addMovie(0, "Choose Or Die", "David Leitch", 134);
    cinema.addMovie(1, "Fall Guys", "David Leitch", 128);
    cinema.addMovie(2, "Interstellar", "David Leitc", 174);
    cinema.displayCinemaDetails();
    return 0;
}
