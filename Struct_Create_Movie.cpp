#include <iostream>
#include <limits>
using namespace std;

struct Date {//struct of Date 
    int releaseYear;
    short releaseMonth;
    short releaseDay;
};

//overloaded << for Date
ostream& operator<<(ostream& O_stream, const Date& DATE) {//instead of cout the Date, we use ostream to chain the Date
    O_stream <<DATE.releaseYear << "-" <<DATE.releaseMonth << "-" << DATE.releaseDay;
    return O_stream;//returning the O_stream that has the Date members
}

struct Movie {//struct of Movie 
    string title;
    Date D_release;//creating object of Date as a member of Movie 
    bool isPopular;
};

//overloaded << for Movie
ostream& operator<<(ostream& O_stream, const Movie& mov) {//instead of cout the Movie, we use ostream to chain the Movie
    O_stream << "Title: " << mov.title << "\n"
       << "Release Date: " << mov.D_release << "\n"//has the Date member
       << "Popular: " << (mov.isPopular ? "Yes" : "No");
    return O_stream;//return the O_stream which has the Movie member
}

//input validation functions
int getValidInt(string prompt, int min, int max) {//passing prompt,min,max as a argument 
    int value;
    while (true) {// it keeps asking to input until valid input is entered
        cout << prompt;//prompting the user
        cin >> value;//input the value 
        if (cin.fail() || value < min || value > max) {// checks if input is invalid (not an integer) or input is less than min or greater than max(out of the range)
            cin.clear();//
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore the character in the input buffer
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";//print
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//else retrun the value
            return value;
        }
    }
}

//function to create a Movie
Movie createMovie() {
    string title;
    cout << "Enter movie title: ";//prompting a user 
    getline(cin, title);// input the title

    short year = getValidInt("Enter release year (1900-2100): ", 1900, 2100);// we are calling the getValidInt function to check if the input is valid 
    short month = getValidInt("Enter release month (1-12): ", 1, 12);//same for month
    short day = getValidInt("Enter release day (1-31): ", 1, 31);//same for day

    char popular;
    bool isPopular;
    while (true) {//infinite loop that will keep running until the user enters a valid input
        cout << "Is the movie popular? (y/n): ";
        cin >> popular;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear the input leftover
        if (popular == 'y' || popular == 'Y') {//if user puts y or Y  
            isPopular = true;//isPopular is true
            break;
        } else if (popular == 'n' || popular == 'N') {//else if isPopular false
            isPopular = false;
            break;
        } else {//else print invalid input
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }

    return Movie{title, {year, month, day}, isPopular};//returning the Movie struct
}

int main() {
    Movie myMovie = createMovie();//creating a object called myMovie and assign to the createMovie function 
    cout << "\nMovie Details:\n" << myMovie << endl;//cout the object myMovie

    return 0;
}