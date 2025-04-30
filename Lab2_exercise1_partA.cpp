// Lab 2 Exercise 1 Part A

#include <iostream>
using namespace std;

int main() {
    int kokonaisluku1, kokonaisluku2;

    // prompt user for two integers
    cout << "Enter the first integer: ";
    cin >> kokonaisluku1;
    
    cout << "Enter the second integer: ";
    cin >> kokonaisluku2;

    // calculate product of the two numbers
    int tulo = kokonaisluku1 * kokonaisluku2;

    // display result
    cout << "The product of " << kokonaisluku1 << " and " << kokonaisluku2 << " is: " << tulo << endl;

    // for executable file
    cout << "press Enter to exit";
    cin.ignore();    
    cin.get();
    return 0;
    
}