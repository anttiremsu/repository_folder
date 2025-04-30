// Lab 3 assignment 4.3

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

    // Make showInfo a pure virtual function
    virtual void showInfo() = 0;

    // start engine now need to be virtual to be overridable
    virtual void startEngine() {
        std::cout << "Starting engine of Vehicle" << std::endl;
    }
};

// derived car class for base class vehicle
class Car : public Vehicle {
    // needs to be changed from private to protected to grant access to derived classes
    protected:
        int numDoors;
    
    public:
        // Constructor: takes brand, year, and numDoors and calls the base constructor
        Car(const std::string& brand, int year, int numDoors) 
            : Vehicle(brand, year), numDoors(numDoors) {}
    
        // Override showInfo() to display all 3 attributes
        virtual void showInfo() override {
            std::cout << "Brand: " << brand << ", Year: " << year 
                      << ", Number of Doors: " << numDoors << std::endl;
        }
    
        // Override startEngine() to print: "Car engine is starting!"
        virtual void startEngine() override {
            std::cout << "Car engine is starting!" << std::endl;
        }
    };

// the derived ElectricCar class inherits from derived class Car
// derived classes can have recursion in inheritance
class ElectricCar : public Car {
    private:
        int batteryCapacity; // battery size in kWh
    
    public:
        // Default constructor: Sets batteryCapacity to 0
        ElectricCar() : Car("", 0, 0), batteryCapacity(0) {}
    
        // constructor for all info
        ElectricCar(const std::string& brand, int year, int numDoors, int batteryCapacity)
            : Car(brand, year, numDoors), batteryCapacity(batteryCapacity) {}
    
        // Override showInfo() to display all attributes
        void showInfo() override {
            std::cout << "Brand: " << brand << ", Year: " << year
                      << ", Number of Doors: " << numDoors
                      << ", Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
        }
    
        // Override startEngine() again for electric car prompt text
        void startEngine() override {
            std::cout << "Electric engine is starting... Silent but powerful!" << std::endl;
        }
    };


int main() {
    // direct vehicle not possible anymore

    // Create a Car object
    Vehicle* kaara = new Car("Lada", 1955, 4);
    kaara->showInfo();
    kaara->startEngine();
    delete kaara;

    // Create an ElectricCar object using the default constructor
    ElectricCar* patteriauto = new ElectricCar();
    patteriauto->showInfo();
    patteriauto->startEngine();
    delete patteriauto;

    // Create an ElectricCar object using the parameterized constructor
    ElectricCar* paramElectricCar = new ElectricCar("sitikka", 2023, 4, 600);
    paramElectricCar->showInfo();
    paramElectricCar->startEngine();
    delete paramElectricCar;

    return 0;
}

// A: inheritance allows derived classes to use structure, data and functions of base class.
// access is defined by specifiers private, protected and public.
// private is not accessible
// protected is accessible only to derived class(es)
// public accessible thorughout program
// B: The main difference is whether user wants to define all data at creation or later
// overloading allows to make variations of a function
// this is good for several reasons:
// code can use same commands in different scenarios, adaptive design 
// and less repetition of same stuff in code
// allows to input data even when not all data for object is known
// if functionality:cmdlines ratio is critical, overloading is more effective
// C: then compiler uses default constructor, if no default then error at compile