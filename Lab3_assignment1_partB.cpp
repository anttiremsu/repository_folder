// Lab 3 assignment 1 part B

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

    void setDetails(string petersbook){
        title = petersbook;
    }
};

int main(){
    Book book1; 
    book1.publisher = "kustantamo"; // Set publisher value
    cout << book1.publisher << endl; // Print publisher
    }

// for fixing several mistakes but also because private is restricted access but public is not