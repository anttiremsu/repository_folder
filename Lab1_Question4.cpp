// Lab 1 Question 4

#include <iostream>
using namespace std;

// Macro to calculate the square of a number
#define SQUARE(x) ((x) * (x))

int main() {
    int numero;

    // Take an integer input from the user
    cout << "Enter an integer: ";
    cin >> numero;

    // Use the SQUARE macro to calculate and print the square
    cout << "The square of " << numero << " is " << SQUARE(numero) << endl;

    // for executable file
    std::cout << "press Enter to exit"; 
    std::cin.get();
    std::cin.get();
    return 0;
}