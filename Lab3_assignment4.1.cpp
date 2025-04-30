// Lab 3 assignment 4.1

#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;

public:
    // Constructor init brand and year
    Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

    // display brand and year
    void showInfo() {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }

    // start engine
    void startEngine() {
        std::cout << "Starting engine of Vehicle" << std::endl;
    }
};

int main() {
    // Create Vehicle object
    Vehicle* kaara = new Vehicle("Lada", 1955);

    // Display vehicle info
    kaara->showInfo();

    // Start engine
    kaara->startEngine();

    return 0;
}