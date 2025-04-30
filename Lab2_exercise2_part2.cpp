// Lab 2 Exercise 2 part 2

#include <iostream>
using namespace std;

void swapUsingPointers(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float x = 1, y = 2; // insert values to be swapped here

    // Prompt the user for two integers
    cout << "Enter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y; 

    swapUsingPointers(&x, &y); // swap
    cout << x;
    cout << " and "; 
    cout << y; // output in the swapped order

    cout << "press Enter to exit"; // for executable file
    cin.ignore();    
    cin.get(); 
    return 0;
}