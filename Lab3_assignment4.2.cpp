// Lab 3 assignment 4.2

#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;

public:
    // Constructor init brand and year
    Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

    // explicit virtual destructr needed for derived object delete
    virtual ~Vehicle() {
        std::cout << brand << " deleted " << std::endl;
    }

    // display brand and year now needs to be virtual to be overridable
    virtual void showInfo() {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    // start engine now need to be virtual to be overridable
    virtual void startEngine() {
        std::cout << "Starting engine of Vehicle" << std::endl;
    }
};

// the derived car class for base class vehicle
class Car : public Vehicle {
    private:
        int numDoors;
    
    public:
        // Constructor: takes brand, year, and numDoors and calls the base constructor
        Car(const std::string& brand, int year, int numDoors) 
            : Vehicle(brand, year), numDoors(numDoors) {}
    
        // Override showInfo() to display all 3 attributes
        void showInfo() override {
            std::cout << "Brand: " << brand << ", Year: " << year 
                      << ", Number of Doors: " << numDoors << std::endl;
        }
    
        // Override startEngine() to print: "Car engine is starting!"
        void startEngine() override {
            std::cout << "Car engine is starting!" << std::endl;
        }
    };

int main() {
    // Create Vehicle object
    Vehicle* kaara = new Vehicle("Lada", 1955);

    // Display vehicle info
    kaara->showInfo();

    // Start engine
    kaara->startEngine();

    // explicit delete for object kaara
    delete kaara;
    return 0;
}