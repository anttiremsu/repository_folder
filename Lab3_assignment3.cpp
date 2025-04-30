// Lab 3 assignment 3

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    // construct in class Car with printout
    Car(string b, int y) : brand(b), year(y) {
        cout << "Car " << brand << " from " << year << " created." << endl;
    }

    // destructor with printout
    ~Car() {
        cout << "Car " << brand << " destroyed." << endl;
    }

    // display information
    void showInfo() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    // Create new lada car object on heap
    Car* kaara = new Car("Lada", 1955);

    // call for showInfo
    kaara->showInfo();

    // destroy kaara that is the lada
    delete kaara;

    return 0;
}

// A: constructor is needed for proper init of object, all variables get values etc.
// constructor also simplifies creation of new objects and makes code easier to work with
// B: destructor is sort of constructor in reverse. it makes sure all data is properly erased
// this way resources used by object destroyed are freed for new use and no memory problems
// C: lines 13-20. No values are returned from either constructor or destructor.
// they are automatic functions, they are not defined by programmer/user.
// destructor also activates automagically when object is out of scope
// D: with new object is in heap. with stack it is in stack. Heap is for longer storage
// with stack the object is deleted instantly when out of scope.
// with heap program/user must delete manually/explicitly
// E: automated default constructor is called but it has no info on variables/attributes.
// this can create problems such as random values and unexpected behaviour
// F: default automated destructor call is sufficient in most cases
// custom destructor is usually not needed but dynamic memory problems can happen in some cases