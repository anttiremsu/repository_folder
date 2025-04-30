// Lab 3 assignment 1 part A

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
    displayAuthorInfo();

    void setDetails(string petersbook){
        title = petersbook;
    }

}


int main(){
    Book book1; 
    book1.setDetails("petersbook", 550, "peter");
    book1.showDetails();
    }

// it does not compile because we are trying to access the variable title, which is private