// Lab1 Question 5

#include <iostream>
using namespace std;

int main() {
    int numero, summa = 0;

    // Take input from user
    cout << "Enter an integer: ";
    cin >> numero;

    // calculate sum of input number digits using a for loop
    for (; numero != 0; numero /= 10) {
        // Add the last digit to the sum using modulus operation
        summa += numero % 10; 
    }

    // print output
    cout << "The summa of the digits is: " << summa << endl;

    // for executable file
    cout << "Press Enter to exit";
    cin.ignore();
    cin.get();
    return 0;
}