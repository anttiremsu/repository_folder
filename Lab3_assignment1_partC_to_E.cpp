// Lab 3 assignment 1 part C to E

#include <iostream>
using namespace std;

class Book {

    private:
    string title; // this cannot be accessed directly from the outside
    int pages;
    string Author;

    protected:
    float price;

    public:
    string publisher;

    // Define displayAuthorInfo
    void displayAuthorInfo() {
        cout << "Author: " << Author << endl;
    }

    void setDetails(string petersbook){
        title = petersbook;
    }
};

int main(){
    Book book1; 
    book1.publisher = "kustantamo"; // Set publisher value
    cout << book1.publisher << endl; // Print publisher
    book1.displayAuthorInfo(); // print using function
    }

// here it works because the function displayAuthorInfo is within the class Book 
// and so gives sort of indirect access

// D: the 3 types are the private protected and public

// E: class is the combined data type, where interrelated data is grouped
// classes are needed so data can be accessed and utilized in a meaningful way
// for example allowing existence of objects
// where correlations/connections remain (fairly) structured